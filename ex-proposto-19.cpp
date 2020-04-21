#include <iomanip>
#include <iostream>

using namespace std;

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

    cout << "O aluno " << nome << " teve média " << fixed << setprecision(1) << media << "." << endl;

}
