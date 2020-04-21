#include <iomanip>
#include <iostream>
#include <stdlib.h>

#include "ListaLinearVetor.h"

using namespace std;

#define MEDIA_MINIMA    6

struct Aluno {
    string matricula;
    string nome;
    double p1, p2;

    double media()
    {
        return (p1 + p2) / 2;
    }

    bool aprovado()
    {
        return media() >= MEDIA_MINIMA;
    }

    void leDados()
    {
        string p1s, p2s;

        cout << "Matrícula: ";
        getline(cin, matricula);

        cout << "Nome: ";
        getline(cin, nome);

        cout << "P1: ";
        getline(cin, p1s);

        cout << "P2: ";
        getline(cin, p2s);

        p1 = atoi(p1s.c_str());
        p2 = atoi(p2s.c_str());
    }

    void imprime()
    {
        cout << matricula << " - " << nome;
    }
};

int procura(Lista<Aluno> &sala, string matricula)
{
    int indice = -1;

    for(int i = 0; i < sala.quantidade(); i++) {
        Aluno aluno = sala.acesso(i);
        if(aluno.matricula == matricula) {
            indice = i;
            break;
        }
    }

    return indice;
}

int procuraPosicao(Lista<Aluno> &sala, string nome)
{
    int indice = 0;

    for(int i = 0; i < sala.quantidade(); i++) {
        Aluno aluno = sala.acesso(i);
        if(aluno.nome > nome) {
            indice = i;
            break;
        }
    }

    return indice;
}

int listaAlunos(Lista<Aluno> &sala, bool aprovados)
{
    int quantidade = 0;

    for(int i = 0; i < sala.quantidade(); i++) {
        Aluno aluno = sala.acesso(i);
        if(aluno.aprovado() == aprovados) {
            aluno.imprime();
            cout << " - ";
            cout << aluno.media();
            cout << endl;
            quantidade++;
        }
    }

    return quantidade;
}

int main()
{
    Lista<Aluno> sala(1000); // a sala pode ter, no máximo, 1000 alunos

    bool sair = false;
    do {
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Listar alunos" << endl;
        cout << "3 - Consultar aluno" << endl;
        cout << "4 - Atualizar aluno" << endl;
        cout << "5 - Remover aluno" << endl;
        cout << "6 - Listar alunos aprovados" << endl;
        cout << "7 - Listar alunos reprovados" << endl;
        cout << "8 - Sair" << endl;
        cout << "Sua opção: ";
        string opcao;
        getline(cin, opcao);
        cout << endl;

        if(opcao == "1") {
            if(sala.cheia()) {
                cout << "Capacidade máxima atingida." << endl;
            } else {
                Aluno novo;
                novo.leDados();
                int indice = procura(sala, novo.matricula);
                if(indice >= 0) {
                    cout << "Já existe aluno com essa matrícula." << endl;
                } else {
                    int posicao = procuraPosicao(sala, novo.nome);
                    bool sucesso = sala.insere(novo, posicao);
                    if(sucesso) {
                        cout << "Aluno cadastrado." << endl;
                    } else {
                        cout << "Erro o cadastrar o aluno." << endl;
                    }
                }
            }
        } else if(opcao == "2") {
            if(sala.vazia()) {
                cout << "Nenhum aluno cadastrado. Capacidade: " << sala.capacidade() << endl;
            } else {
                for(int i = 0; i < sala.quantidade(); i++) {
                    Aluno aluno = sala.acesso(i);
                    aluno.imprime();
                    cout << endl;
                }
                cout << "Quantidade de alunos: " << sala.quantidade() << endl;
            }
        } else if(opcao == "3") {
            string matricula;
            cout << "Matrícula: ";
            getline(cin, matricula);

            int indice = procura(sala, matricula);
            if(indice < 0) {
                cout << "Não foi encontrado um aluno com essa matrícula." << endl;
            } else {
                Aluno aluno = sala.acesso(indice);
                aluno.imprime();
                cout << " - P1: " << aluno.p1 << " - P2: " << aluno.p2 << endl;
            }
        } else if(opcao == "4") {
            string matricula;
            cout << "Matrícula: ";
            getline(cin, matricula);

            int indice = procura(sala, matricula);
            if(indice < 0) {
                cout << "Não foi encontrado um aluno com essa matrícula." << endl;
            } else {
                cout << "Entre com os novos dados: " << endl;
                Aluno aluno;
                aluno.leDados();
                sala.atualiza(indice, aluno);
            }
        } else if(opcao == "5") {
            string matricula;
            cout << "Matrícula: ";
            getline(cin, matricula);

            int indice = procura(sala, matricula);
            if(indice < 0) {
                cout << "Não foi encontrado um aluno com essa matrícula." << endl;
            } else {
                sala.remover(indice);
            }
        } else if(opcao == "6") {
            int quantidade = listaAlunos(sala, true);
            cout << "Aluno aprovados: " << quantidade << endl;
        } else if(opcao == "7") {
            int quantidade = listaAlunos(sala, false);
            cout << "Aluno reprovados: " << quantidade << endl;
        } else if(opcao == "8") {
            sair = true;
        }

        cout << endl;
    } while(!sair);
}
