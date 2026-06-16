#include <iostream>
using namespace std;

void binario(int n, int bits)
{
    for(int i = bits - 1; i >= 0; i--)
        cout << ((n >> i) & 1);
}

int binarioADecimal(string bin)
{
    int n = 0;

    for(char c : bin)
        n = n * 2 + (c - '0');

    return n;
}

void decimalABinario()
{
    int n, bits;

    cout << "Numero decimal: ";
    cin >> n;

    cout << "Cantidad de bits: ";
    cin >> bits;

    int mask = (1 << bits) - 1;
    int magnitud = abs(n);

    cout << "\nSigno Magnitud : ";

    if(n < 0)
        cout << "1";
    else
        cout << "0";

    binario(magnitud, bits - 1);

    cout << endl;

    if(n >= 0)
    {
        cout << "Complemento 1  : ";
        binario(n, bits);

        cout << "\nComplemento 2  : ";
        binario(n, bits);
    }
    else
    {
        int c1 = (~magnitud) & mask;
        int c2 = (c1 + 1) & mask;

        cout << "Complemento 1  : ";
        binario(c1, bits);

        cout << "\nComplemento 2  : ";
        binario(c2, bits);
    }

    cout << endl;
}

void binarioADec()
{
    string bin;

    cout << "Numero binario: ";
    cin >> bin;

    int tipo;

    cout << "\n1. Signo Magnitud";
    cout << "\n2. Complemento 1";
    cout << "\n3. Complemento 2";
    cout << "\nTipo: ";
    cin >> tipo;

    int bits = bin.size();

    if(tipo == 1)
    {
        int signo = bin[0] - '0';

        int valor = 0;

        for(int i = 1; i < bits; i++)
            valor = valor * 2 + (bin[i] - '0');

        if(signo)
            cout << "Decimal = -" << valor << endl;
        else
            cout << "Decimal = " << valor << endl;
    }
    else if(tipo == 2)
    {
        int valor = binarioADecimal(bin);

        if(bin[0] == '1')
        {
            int mask = (1 << bits) - 1;
            valor = (~valor) & mask;

            cout << "Decimal = -" << valor << endl;
        }
        else
        {
            cout << "Decimal = " << valor << endl;
        }
    }
    else
    {
        int valor = binarioADecimal(bin);

        if(bin[0] == '1')
        {
            int mask = (1 << bits) - 1;
            valor = ((~valor) + 1) & mask;

            cout << "Decimal = -" << valor << endl;
        }
        else
        {
            cout << "Decimal = " << valor << endl;
        }
    }
}

void sumarBinarios()
{
    string a, b;

    cout << "Primer binario : ";
    cin >> a;

    cout << "Segundo binario: ";
    cin >> b;

    int n1 = binarioADecimal(a);
    int n2 = binarioADecimal(b);

    int suma = n1 + n2;

    int bits = max(a.size(), b.size()) + 1;

    cout << "\nResultado:\n";

    binario(n1, bits);
    cout << endl;

    binario(n2, bits);
    cout << endl;

    for(int i = 0; i < bits; i++)
        cout << "-";
    cout << endl;

    binario(suma, bits);

    cout << "\nDecimal = " << suma << endl;
}

void restarBinarios()
{
    string a, b;

    cout << "Minuendo   : ";
    cin >> a;

    cout << "Sustraendo : ";
    cin >> b;

    int bits = max(a.size(), b.size());

    int A = binarioADecimal(a);
    int B = binarioADecimal(b);

    int mask = (1 << bits) - 1;

    int c2 = ((~B) + 1) & mask;

    int resultado = A + c2;

    cout << "\nProceso:\n";

    cout << "A                 = ";
    binario(A, bits);

    cout << "\nB                 = ";
    binario(B, bits);

    cout << "\nComplemento a 2 B = ";
    binario(c2, bits);

    cout << "\n";

    for(int i = 0; i < bits; i++)
        cout << "-";

    cout << "\n";

    binario(resultado, bits);

    cout << endl;

    if(resultado & (1 << bits))
    {
        cout << "Acarreo descartado\n";
        resultado &= mask;
    }

    cout << "Resultado = ";
    binario(resultado, bits);

    cout << " (" << (A - B) << ")" << endl;
}

int main()
{
    int op;

    do
    {
        cout << "\n===== MENU =====";
        cout << "\n1. Decimal -> Binario";
        cout << "\n2. Binario -> Decimal";
        cout << "\n3. Sumar Binarios";
        cout << "\n4. Restar Binarios (C2)";
        cout << "\n5. Salir";
        cout << "\nOpcion: ";
        cin >> op;

        switch(op)
        {
            case 1:
                decimalABinario();
                break;

            case 2:
                binarioADec();
                break;

            case 3:
                sumarBinarios();
                break;

            case 4:
                restarBinarios();
                break;
        }

    } while(op != 5);

    return 0;
}