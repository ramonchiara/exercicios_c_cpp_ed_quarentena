#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "PilhaVetor.h"

using namespace std;

struct Disco {
    int tamanho;

    Disco()
    {
        tamanho = 0;
    }

    Disco(int tam)
    {
        tamanho = tam;
    }
};

struct Torre {
    // https://stackoverflow.com/questions/11490988/c-compile-time-error-expected-identifier-before-numeric-constant
    Pilha<Disco> p = Pilha<Disco>(4);

    void insere(Disco d)
    {
        p.empilha(d);
    }

    Disco remove()
    {
        Disco d = p.desempilha();

        // gambi... :-(
        Disco vazio(0);
        p.empilha(vazio);
        p.desempilha();

        return d;
    }

    int getTamanhoDisco(int altura)
    {
        int tamanho = 0;

        if(altura < p.getTamanho()) {
            Disco d = p.getValor(altura);
            tamanho = d.tamanho;
        }

        return tamanho;
    }
};

void pino()
{
    cout << "   |   ";
}

void espaco()
{
    cout << "    ";
}

void disco(int tamanho)
{
    int branco = 3 - tamanho;
    int cheio = 2 * tamanho + 1;

    for(int i = 0; i < branco; i++) {
        cout << " ";
    }
    for(int i = 0; i < cheio; i++) {
        cout << "=";
    }
    for(int i = 0; i < branco; i++) {
        cout << " ";
    }
}

void item(Torre &t, int altura)
{
    int tamanho = t.getTamanhoDisco(altura);

    if(tamanho == 0) {
        pino();
    } else {
        disco(tamanho);
    }
}

void imprime(Torre &t1, Torre &t2, Torre &t3)
{
    for(int altura = 3; altura >= 0; altura--) {
        item(t1, altura);
        espaco();
        item(t2, altura);
        espaco();
        item(t3, altura);
        cout << endl;
    }
    cout << "Torre 1";
    espaco();
    cout << "Torre 2";
    espaco();
    cout << "Torre 3";
    cout << endl;
}

bool valido(Torre &de, Torre &para)
{
    return para.p.pilhaVazia() || para.p.elementoDoTopo().tamanho > de.p.elementoDoTopo().tamanho;
}

int main()
{
    Torre torres[3];

    Disco d1(1);
    Disco d2(2);
    Disco d3(3);

    torres[0].insere(d3);
    torres[0].insere(d2);
    torres[0].insere(d1);

    do {
        imprime(torres[0], torres[1], torres[2]);
        cout << endl;

        int de, para;
        cout << "Mover da torre: ";
        cin >> de;
        cout << "Para a torre: ";
        cin >> para;

        // ajusta índices
        de -= 1;
        para -= 1;

        if(valido(torres[de], torres[para])) {
            Disco d = torres[de].remove();
            torres[para].insere(d);
        } else {

            cout << "Movimento inválido (não pode colocar um disco maior em cima de um menor)" << endl;
        }

        cout << endl;
    } while(true);
}
