#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int to_int(char c)
{
    return c - '0';
}

struct PisPasep {
    char numero[12]; // 10 d�gitos + 1 dv + '\0'
    int dv;

    PisPasep(char entrada[])
    {
        snprintf(numero, 12, "%s", entrada);
        dv = calculaDv();
    }

    bool ehValido()
    {
        int tamanho = strlen(numero);

        bool so_numeros = true;
        for(int i = 0; i < tamanho; i++) {
            if(numero[i] < '0' || numero[i] > '9') {
                so_numeros = false;
                break;
            }
        }

        return (tamanho == 10 || tamanho == 11) && so_numeros;
    }

    int calculaDv()
    {
        int digitos[] = { 3, 2, 9, 8, 7, 6, 5, 4, 3, 2 }; // 10 d�gitos

        int soma = 0;
        for(int i = 0; i < 10; i++) {
            soma += to_int(numero[i]) * digitos[i];
        }

        int dv = 11 - soma % 11;
        if(dv == 10) {
            dv = 0;
        }

        return dv;
    }

    bool temDv()
    {
        return numero[10] != '\0';
    }

    bool dvValido()
    {
        return to_int(numero[10]) == dv;
    }
};


int main()
{
    char entrada[12]; // 10 d�gitos + 1 dv + '\0'

    cout << "Entre com o n�mero PIS/PASEP sem s�mbolos: ";
    cin >> entrada;

    PisPasep p(entrada);

    // verifica��o extra...
    if(!p.ehValido()) {
        cout << "O n�mero entrado n�o � v�lido..." << endl;
    }

    cout << "O d�gito verificador � " << p.dv << "." << endl;

    // Se a entrada tiver um DV no final, vamos valid�-lo...
    if(p.temDv()) {
        if(p.dvValido()) {
            cout << "DV v�lido." << endl;
        }     else {
            cout << "DV inv�lido!" << endl;
        }
    }
}
