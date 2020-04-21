#include <iostream>

using namespace std;

int main()
{
    char sn;

    do {
        cout << "Pense em um número entre 1 e 10. Pensou? (s/n): ";
        cin >> sn;
        sn = toupper(sn);
    } while(sn != 'S');

    int menor = 1, maior = 10, tentativa;
    bool acertou = false;
    do {
        tentativa = (menor + maior) / 2;

        do {
            cout << "É o " << tentativa << "? (s/n): ";
            cin >> sn;
            sn = toupper(sn);
        } while(sn != 'S' && sn != 'N');

        if(sn == 'S') {
            cout << "Acertei!!!" << endl;
            acertou = true;
        } else {
            do {
                cout << "É maior ou menor? (</>): ";
                cin >> sn;
            } while(sn != '<' && sn != '>');

            if(sn == '<') {
                maior = tentativa - 1;
            } else {
                menor = tentativa + 1;
            }
        }
    } while(!acertou);
}
