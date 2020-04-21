#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MEDIA_MINIMA    6
#define N               20

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

int main()
{
    Aluno alunos[N];

    for(int i = 0; i < N; i++) {
        string nome, p1, p2;

        cout << "Nome do " << (i + 1) << "o aluno: ";
        getline(cin, nome);

        cout << "P1: ";
        getline(cin, p1);

        cout << "P2: ";
        getline(cin, p2);

        alunos[i].nome = nome;
        alunos[i].p1 = atof(p1.c_str());
        alunos[i].p2 = atof(p2.c_str());
    }

    cout << endl;

    cout << "Alunos APROVADOS" << endl;
    for(int i = 0; i < N; i++) {
        if(alunos[i].aprovado()) {
            cout << alunos[i].nome << " - " << fixed << setprecision(1) << alunos[i].media() << endl;
        }
    }

    cout << endl;

    cout << "Alunos REPROVADOS" << endl;
    for(int i = 0; i < N; i++) {
        if(!alunos[i].aprovado()) {
            cout << alunos[i].nome << " - " << fixed << setprecision(1) << alunos[i].media() << endl;
        }
    }
}
