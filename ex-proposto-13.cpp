#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int sorteado = rand() % 10 + 1; // sorteia n�mero entre 1 e 10
    int tentativa;
    int quantas = 0;

    cout << "Pensei em um n�mero entre 1 e 10. Adivinhe qual �..." << endl;

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
                cout << "� um n�mero maior..." << endl;
            } else {
                cout << "� um n�mero menor..." << endl;
            }
        }
    } while(!acertou);
}
