#include <iostream>

using namespace std;

int to_int(char c)
{
    return c - '0';
}

int main()
{
    char entrada[12]; // 10 dígitos + 1 dv + '\0'
    int digitos[] = { 3, 2, 9, 8, 7, 6, 5, 4, 3, 2 }; // 10 dígitos

    cout << "Entre com o número PIS/PASEP sem símbolos: ";
    cin >> entrada;

    int soma = 0;
    for(int i = 0; i < 10; i++) {
        soma += to_int(entrada[i]) * digitos[i];
    }

    int dv = 11 - soma % 11;
    if(dv == 10) {
        dv = 0;
    }

    cout << "O dígito verificador é " << dv << "." << endl;

    // Se a entrada tiver um DV no final, vamos validá-lo...
    if(entrada[10] != '\0') {
        if(to_int(entrada[10]) == dv) {
            cout << "DV válido." << endl;
        }     else {
            cout << "DV inválido!" << endl;
        }
    }
}
