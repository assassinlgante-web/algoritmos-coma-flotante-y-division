#include <iostream>
#include <cmath>
using namespace std;

void convertirFraccion(double frac, int bits = 30)
{
    for(int i = 0; i < bits; i++)
    {
        frac *= 2;

        if(frac >= 1)
        {
            cout << "1";
            frac -= 1;
        }
        else
        {
            cout << "0";
        }
    }
}

int main()
{
    double num;

    cout << "Numero: ";
    cin >> num;

    // Paso 1: Signo
    int signo = (num < 0);

    if(num < 0)
        num = -num;

    int entero = (int)num;
    double decimal = num - entero;

    cout << "\nPASO 1: SIGNO\n";
    cout << "S = " << signo << endl;

    // Parte entera a binario
    string binEntero = "";

    int aux = entero;

    while(aux > 0)
    {
        binEntero = char((aux % 2) + '0') + binEntero;
        aux /= 2;
    }

    cout << "\nPASO 2: BINARIO\n";
    cout << entero << " = " << binEntero << endl;

    cout << "Parte decimal: ";

    string binDecimal = "";

    double frac = decimal;

    for(int i = 0; i < 20; i++)
    {
        frac *= 2;

        if(frac >= 1)
        {
            binDecimal += '1';
            frac -= 1;
        }
        else
        {
            binDecimal += '0';
        }
    }

    cout << "0." << binDecimal << endl;

    cout << "\nNumero binario:\n";
    cout << binEntero << "." << binDecimal << endl;

    // Paso 3: Normalizar
    int exponente = binEntero.size() - 1;

    string mantisa =
        binEntero.substr(1) + binDecimal;

    cout << "\nPASO 3: NORMALIZACION\n";
    cout << "1." << mantisa
         << " x 2^" << exponente << endl;

    // Paso 4: Mantisa IEEE754
    cout << "\nPASO 4: MANTISA (23 bits)\n";

    while(mantisa.size() < 23)
        mantisa += '0';

    mantisa = mantisa.substr(0,23);

    cout << mantisa << endl;

    int exponenteIEEE = exponente + 127;

    cout << "\nExponente real: "
         << exponente << endl;

    cout << "Exponente + 127: "
         << exponenteIEEE << endl;

    string binExp = "";

    aux = exponenteIEEE;

    while(aux > 0)
    {
        binExp = char((aux % 2) + '0') + binExp;
        aux /= 2;
    }

    while(binExp.size() < 8)
        binExp = "0" + binExp;

    cout << "\nIEEE 754 (32 bits)\n";

    cout << signo << " "
         << binExp << " "
         << mantisa << endl;

    return 0;
}