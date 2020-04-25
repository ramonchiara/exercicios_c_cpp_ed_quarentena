#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include "PilhaVetor.h"

using namespace std;

int main()
{
    Pilha<double> pilha(100); // no máximo 100 números
    double visor;
    char comando[50];

    bool sair = false;
    do {
        visor = pilha.pilhaVazia() ? 0 : pilha.elementoDoTopo();

        cout << "Visor: " << visor << endl;
        cout << "> ";
        cin >> comando;

        if(isdigit(comando[0])) {
            double n = atof(comando);
            pilha.empilha(n);
        } else if(toupper(comando[0]) == 'L') {
            while(!pilha.pilhaVazia()) {
                pilha.desempilha();
            }
        } else if(toupper(comando[0]) == 'S') {
            sair = true;
        } else {
            if(pilha.getTamanho() >= 2) {
                double a = pilha.desempilha();
                double b = pilha.desempilha();
                double c;

                switch(comando[0]) {
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                }

                pilha.empilha(c);
            }
        }
    } while(!sair);
}
