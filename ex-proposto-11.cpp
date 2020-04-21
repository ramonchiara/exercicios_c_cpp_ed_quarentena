#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int sorteado = rand() % 10 + 1; // sorteia n�mero entre 1 e 10
    int tentativa;

    cout << "Pensei em um n�mero entre 1 e 10. Adivinhe qual �..." << endl;

    bool acertou = false;
    do {
        cout << "Tentativa: ";
        cin >> tentativa;

        if(tentativa == sorteado) {
            cout << "Acertou!" << endl;
            acertou = true;
        } else {
            cout << "Errou." << endl;
        }
    } while(!acertou);
}
