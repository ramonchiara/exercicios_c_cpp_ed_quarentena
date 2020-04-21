#include <iostream>

using namespace std;

void espaco(int n);
void pinheiro(int n);
void base(int n);

int main()
{
    int altura;
    bool valido;

    do {
        cout << "Entre com a altura do pinheiro (entre 3 e 10): ";
        cin >> altura;

        valido = altura >= 3 && altura <= 10;

        if(!valido) {
            cout << "Altura inválida..." << endl;
        }
    } while(!valido);

    for(int a = 0, largura = 1; a < altura ; a++, largura += 2) {
        espaco(altura - a - 1);
        pinheiro(largura);
    }
    base(altura);
}

void espaco(int n)
{
    for(int i = 0; i < n; i++) {
        cout << " ";
    }
}

void pinheiro(int n)
{
    for(int i = 0; i < n; i++) {
        cout << "X";
    }
    cout << endl;
}

void base(int n)
{
    espaco(n - 2);
    pinheiro(3);
    espaco(n - 2);
    pinheiro(3);
    espaco(n - 3);
    pinheiro(5);
}
