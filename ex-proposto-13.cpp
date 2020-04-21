#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int sorteado = rand() % 10 + 1; // sorteia número entre 1 e 10
    int tentativa;
    int quantas = 0;

    cout << "Pensei em um número entre 1 e 10. Adivinhe qual é..." << endl;

    bool acertou = false;
    do {
        quantas++;
        cout << "Tentativa: ";
        cin >> tentativa;

        if(tentativa == sorteado) {
            cout << "Acertou em " << quantas << " tentativa(s)!" << endl;
            acertou = true;
        } else {
            if(sorteado > tentativa) {
                cout << "É um número maior..." << endl;
            } else {
                cout << "É um número menor..." << endl;
            }
        }
    } while(!acertou);
}
