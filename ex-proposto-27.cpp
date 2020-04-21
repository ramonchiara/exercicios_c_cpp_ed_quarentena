#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "FilaCircularVetor.h"

using namespace std;

struct Aviao {
    string nome;
    int id;

    void leDados()
    {
        cout << "Nome: ";
        getline(cin, nome);;

        string ids;
        cout << "ID: ";
        getline(cin, ids);
        id = atoi(ids.c_str());
    }

    void imprime()
    {
        cout << "Avião " << nome << " de ID " << id;
    }
};

int main()
{
    Fila<Aviao> pista(5); // A pista tem capacidade para até 5 aviões!

    bool sair = false;
    do {
        cout << "1 - Mostrar a quantidade de aviões aguardando na fila de decolagem" << endl;
        cout << "2 - Autorizar a decolagem do primeiro avião na fila" << endl;
        cout << "3 - Adicionar um avião na fila" << endl;
        cout << "4 - Listar todos os aviões na fila" << endl;
        cout << "5 - Mostrar os dados do primeiro avião da fila" << endl;
        cout << "6 - Sair" << endl;
        cout << "Sua opção: ";
        string opcao;
        getline(cin, opcao);
        cout << endl;

        if(pista.filaVazia() && opcao != "3" && opcao != "6") {
            cout << "Não há aviões na pista..." << endl;
        } else if(opcao == "1") {
            cout << "Existe(m) " << pista.getQtde() << " avião(ões) aguardando na fila de decolagem." << endl;
        } else if(opcao == "2") {
            Aviao autorizado = pista.primeiro();
            autorizado.imprime();
            cout << " autorizado. Decolando..." << endl;
            pista.remover();
        } else if(opcao == "3") {
            if(pista.filaCheia()) {
                cout << "Não pode adicionar aviões porque a pista está na sua capacidade máxima." << endl;
            }  else {
                Aviao novo;
                novo.leDados();
                pista.insere(novo);
            }
        } else if(opcao == "4") {
            for(int i = 0; i < pista.getQtde(); i++) {
                Aviao a = pista.getValor(i);
                a.imprime();
                cout << endl;
            }
        } else if(opcao == "5") {
            Aviao aguardando = pista.primeiro();
            aguardando.imprime();
            cout << " aguardando autorização..." << endl;
        } else if(opcao == "6") {
            sair = true;
        }

        cout << endl;
    } while(!sair);
}
