#include <iomanip>
#include <iostream>

using namespace std;

#define MEDIA_MINIMA    6

int main()
{
    string nome;
    double p1, p2;

    cout << "Nome do aluno: ";
    getline(cin, nome);

    cout << "P1: ";
    cin >> p1;

    cout << "P2: ";
    cin >> p2;

    double media = (p1 + p2) / 2;

    if(media >= MEDIA_MINIMA) {
        cout << "O aluno " << nome << " passou média " << fixed << setprecision(1) << media << "." << endl;
    } else {
        cout << "O aluno " << nome << " não passou média " << fixed << setprecision(1) << media << "." << endl;
    }
}
