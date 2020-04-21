#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "FilaVetor.h"

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
        cout << "Avi�o " << nome << " de ID " << id;
    }
};

int main()
{
    Fila<Aviao> pista(5); // A pista tem capacidade para at� 5 avi�es!

    bool sair = false;
    do {
        cout << "1 - Mostrar a quantidade de avi�es aguardando na fila de decolagem" << endl;
        cout << "2 - Autorizar a decolagem do primeiro avi�o na fila" << endl;
        cout << "3 - Adicionar um avi�o na fila" << endl;
        cout << "4 - Listar todos os avi�es na fila" << endl;
        cout << "5 - Mostrar os dados do primeiro avi�o da fila" << endl;
        cout << "6 - Sair" << endl;
        cout << "Sua op��o: ";
        string opcao;
        getline(cin, opcao);
        cout << endl;

        if(pista.vazia() && opcao != "3" && opcao != "6") {
            cout << "N�o h� avi�es na pista..." << endl;
        } else if(opcao == "1") {
            cout << "Existe(m) " << pista.quantidade() << " avi�o(�es) aguardando na fila de decolagem." << endl;
        } else if(opcao == "2") {
            Aviao autorizado = pista.acesso();
            autorizado.imprime();
            cout << " autorizado. Decolando..." << endl;
            pista.remover();
        } else if(opcao == "3") {
            if(pista.cheia()) {
                cout << "N�o pode adicionar avi�es porque a pista est� na sua capacidade m�xima." << endl;
            }  else {
                Aviao novo;
                novo.leDados();
                pista.insere(novo);
            }
        } else if(opcao == "4") {
            for(int i = 0; i < pista.quantidade(); i++) {
                Aviao a = pista.acesso(i);
                a.imprime();
                cout << endl;
            }
        } else if(opcao == "5") {
            Aviao aguardando = pista.acesso();
            aguardando.imprime();
            cout << " aguardando autoriza��o..." << endl;
        } else if(opcao == "6") {
            sair = true;
        }

        cout << endl;
    } while(!sair);
}
