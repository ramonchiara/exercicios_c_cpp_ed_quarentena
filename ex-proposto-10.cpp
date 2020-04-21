#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int sorteado = rand() % 10 + 1; // sorteia número entre 1 e 10
    int tentativa;

    cout << "Pensei em um número entre 1 e 10. Adivinhe qual é..." << endl;
    cout << "Tentativa: ";
    cin >> tentativa;

    if(tentativa == sorteado) {
        cout << "Acertou!" << endl;
    } else {
        cout << "Errou. O número sorteado era o " << sorteado << "." << endl;
    }
}
