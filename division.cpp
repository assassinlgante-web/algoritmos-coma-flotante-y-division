#include <iostream>
using namespace std;

const int BITS = 4;
const int MASK = (1 << BITS) - 1;

void binario(int n)
{
    n &= MASK;

    for(int i = BITS - 1; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
}

void mostrar(int cuenta, int A, int Q, string operacion)
{
    cout << cuenta << "\t";

    binario(A);
    cout << "\t";

    binario(Q);
    cout << "\t";

    cout << operacion << endl;
}

void mostrarShift(int cuenta, int A, int Q)
{
    cout << cuenta << "\t";

    binario(A);
    cout << "\t";

    for(int i = BITS - 1; i >= 1; i--)
    {
        cout << ((Q >> i) & 1);
    }

    cout << "_";

    cout << "\tShift" << endl;
}

int main()
{
    int Q, M;

    cout << "Dividendo (Q): ";
    cin >> Q;

    cout << "Divisor (M): ";
    cin >> M;

    int A = 0;
    int cuenta = BITS;

    cout << "\nC\tA\tQ\tOPERACION\n";

    mostrar(cuenta, A, Q, "Inicial");

    while(cuenta > 0)
    {
        // Desplazar AQ a la izquierda
        int msbQ = (Q >> (BITS - 1)) & 1;

        A = ((A << 1) | msbQ) & MASK;
        Q = (Q << 1) & MASK;

        mostrarShift(cuenta, A, Q);

        // A = A - M
        A = (A - M) & MASK;

        mostrar(cuenta, A, Q, "A=A-M");

        // Revisar signo (MSB de A)
        if(A & (1 << (BITS - 1)))
        {
            mostrar(cuenta, A, Q, "Q0=0");

            // Restaurar
            A = (A + M) & MASK;

            mostrar(cuenta, A, Q, "A=A+M");
        }
        else
        {
            Q |= 1;

            mostrar(cuenta, A, Q, "Q0=1");
        }

        cuenta--;
    }

    cout << "\nRESULTADO FINAL\n";

    cout << "Residuo  : ";
    binario(A);
    cout << " = " << A << endl;

    cout << "Cociente : ";
    binario(Q);
    cout << " = " << Q << endl;

    return 0;
}