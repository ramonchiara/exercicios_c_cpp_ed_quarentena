#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX_TENTATIVAS 3

int main()
{
    srand(time(NULL));

    int sorteado = rand() % 10 + 1; // sorteia n�mero entre 1 e 10
    int tentativa;
    int quantas = 0;

    cout << "Pensei em um n�mero entre 1 e 10. Adivinhe qual �..." << endl;

    bool acertou = false;
    bool estourou = false;
    do {
        quantas++;
        cout << "Tentativa " << quantas << ": ";
        cin >> tentativa;

        if(quantas == MAX_TENTATIVAS) {
            estourou = true;
        }

        if(tentativa == sorteado) {
            cout << "Acertou em " << quantas << " tentativa(s)!" << endl;
            acertou = true;
        } else if(estourou) {
            cout << "Errou. O n�mero sorteado era o " << sorteado << "." << endl;
        } else {
            if(sorteado > tentativa) {
                cout << "� um n�mero maior..." << endl;
            } else {
                cout << "� um n�mero menor..." << endl;
            }
        }
    } while(!acertou && !estourou);
}
