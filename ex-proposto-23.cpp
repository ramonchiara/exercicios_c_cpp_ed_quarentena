#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MEDIA_MINIMA    6

struct Aluno {
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
};

struct Sala {
    int N, MAX;
    Aluno *alunos;

    Sala(int max)
    {
        N = 0;
        MAX = max;
        alunos = new Aluno[MAX];
    }

    ~Sala()
    {
        delete[] alunos;
    }

    void leAlunos()
    {
        for(int i = 0; i < MAX; i++) {
            string nome, p1, p2;

            cout << "Nome do " << (i + 1) << "o aluno: ";
            getline(cin, nome);
            if(nome == "") {
                break;
            }

            cout << "P1: ";
            getline(cin, p1);

            cout << "P2: ";
            getline(cin, p2);

            alunos[i].nome = nome;
            alunos[i].p1 = atoi(p1.c_str());
            alunos[i].p2 = atoi(p2.c_str());
            N++;
        }
    }

    void imprimeAprovados()
    {
        cout << "Alunos APROVADOS" << endl;
        for(int i = 0; i < N; i++) {
            if(alunos[i].aprovado()) {
                cout << alunos[i].nome << " - " << fixed << setprecision(1) << alunos[i].media() << endl;
            }
        }
    }
    void imprimeReprovados()
    {
        cout << "Alunos REPROVADOS" << endl;
        for(int i = 0; i < N; i++) {
            if(!alunos[i].aprovado()) {
                cout << alunos[i].nome << " - " << fixed << setprecision(1) << alunos[i].media() << endl;
            }
        }
    }
};

int main()
{
    Sala sala(1000); // a sala pode ter, no máximo, 1000 alunos
    sala.leAlunos();
    cout << endl;
    sala.imprimeAprovados();
    cout << endl;
    sala.imprimeReprovados();
}
