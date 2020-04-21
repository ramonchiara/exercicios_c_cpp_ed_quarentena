#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int resposta = 42;
    double pi = 3.1415926535;
    char nome[50] = "Letícia";

    cout << "resposta = " << resposta << endl
         << "pi = " << fixed << setprecision(10) << pi << endl
         << "nome = " << nome << endl;

}
