#include <iostream>

using namespace std;

int to_int(char c)
{
    return c - '0';
}

int main()
{
    char entrada[12]; // 10 d�gitos + 1 dv + '\0'
    int digitos[] = { 3, 2, 9, 8, 7, 6, 5, 4, 3, 2 }; // 10 d�gitos

    cout << "Entre com o n�mero PIS/PASEP sem s�mbolos: ";
    cin >> entrada;

    int soma = 0;
    for(int i = 0; i < 10; i++) {
        soma += to_int(entrada[i]) * digitos[i];
    }

    int dv = 11 - soma % 11;
    if(dv == 10) {
        dv = 0;
    }

    cout << "O d�gito verificador � " << dv << "." << endl;

    // Se a entrada tiver um DV no final, vamos valid�-lo...
    if(entrada[10] != '\0') {
        if(to_int(entrada[10]) == dv) {
            cout << "DV v�lido." << endl;
        }     else {
            cout << "DV inv�lido!" << endl;
        }
    }
}
