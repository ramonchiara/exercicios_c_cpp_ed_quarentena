#include <ctype.h>
#include <iostream>
#include "FilaVetor.h"
#include "PilhaVetor.h"

using namespace std;

int main()
{
    string texto;

    cout << "Entre com o texto: ";
    getline(cin, texto);

    int n = texto.size();

    Fila<char> letras(n);
    Pilha<char> numeros(n);

    for(int i = 0; i < n; i++) {
        char c = texto.at(i);

        if(isdigit(c)) {
            numeros.empilha(c);
        } else {
            letras.insere(c);
        }
    }

    while(!letras.vazia()) {
        char c = letras.acesso();
        letras.remover();
        cout << c;
    }
    while(!numeros.pilhaVazia()) {
        char c = numeros.desempilha();
        cout << c;
    }
    cout << endl;
}
