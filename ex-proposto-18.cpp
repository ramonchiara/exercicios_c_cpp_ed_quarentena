#include <iostream>
#include <string.h>

using namespace std;

#define VAZIO       '.'
#define NUVEM       '*'
#define AEROPORTO   'A'

struct Mapa {
    int L, C;
    char *mapa;
    int qtd_nuvens;
    int qtd_aeroportos;
    int dias;

    Mapa(int l, int c)
    {
        L = l;
        C = c;
        mapa = new char[L * C];
        memset(mapa, VAZIO, L * C);
        qtd_nuvens = 0;
        qtd_aeroportos = 0;
        dias = 0;
    }

    ~Mapa()
    {
        delete[] mapa;
    }

    void setNuvem(int l, int c)
    {
        if(!tem(l, c, NUVEM)) {
            mapa[indice(l, c)] = NUVEM;
            qtd_nuvens++;
        }
    }

    void setAeroporto(int l, int c)
    {
        if(!tem(l, c, AEROPORTO)) {
            mapa[indice(l, c)] = AEROPORTO;
            qtd_aeroportos++;
        }
    }

    void imprime()
    {
        cout << "Dia " << dias << ": " << contaAeroportos() << "/" << qtd_aeroportos << " aeroporto(s)" << endl;
        for(int l = 0; l < L; l++) {
            for(int c = 0; c < C; c++) {
                cout << valor(l, c) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void calcula_proximo_dia()
    {
        char *proximo_dia = new char[L * C];

        for(int l = 0; l < L; l++) {
            for(int c = 0; c < C; c++) {
                proximo_dia[indice(l, c)] = tem_vizinho_nuvem(l, c) ? NUVEM : valor(l, c);
            }
        }

        memcpy(mapa, proximo_dia, L * C);
        dias++;

        delete[] proximo_dia;
    }

    int contaAeroportos()
    {
        int n_aeroportos = 0;

        for(int l = 0; l < L; l++) {
            for(int c = 0; c < C; c++) {
                if(tem(l, c, AEROPORTO)) {
                    n_aeroportos++;
                }
            }
        }

        return n_aeroportos;
    }

    bool tem_vizinho_nuvem(int l, int c)
    {
        return tem(l - 1, c, NUVEM) || tem(l + 1, c, NUVEM) || tem(l, c - 1, NUVEM) || tem(l, c + 1, NUVEM);
    }

    bool tem(int l, int c, char elemento)
    {
        return posicao_valida(l, c) && valor(l, c) == elemento;
    }

    char valor(int l, int c)
    {
        return mapa[indice(l, c)];
    }

    int indice(int l, int c)
    {
        return l * C + c;
    }

    void le_posicao(int i, int *l, int *c)
    {
        bool valida = false;
        do {
            cout << "Entre com a linha  da " << (i + 1) << "a posição: ";
            cin >> *l;
            cout << "Entre com a coluna da " << (i + 1) << "a posição: ";
            cin >> *c;

            if(posicao_valida(*l, *c)) {
                valida = true;
            } else {
                cout << "Posição inválida..." << endl;
            }
        } while(!valida);
    }

    bool posicao_valida(int l, int c)
    {
        return l >= 0 && l < L && c >= 0 && c < C;
    }
};

int main()
{
    int l, c;
    cout << "Entre com o número de linhas.: ";
    cin >> l;
    cout << "Entre com o número de colunas: ";
    cin >> c;

    Mapa mapa(l, c);

    int qtd;
    cout << "Quantas nuvens? ";
    cin >> qtd;
    for(int i = 0; i < qtd; i++) {
        mapa.le_posicao(i, &l, &c);
        mapa.setNuvem(l, c);
    }
    cout << "Quantos aeroportos? ";
    cin >> qtd;
    for(int i = 0; i < qtd; i++) {
        mapa.le_posicao(i, &l, &c);
        mapa.setAeroporto(l, c);
    }

    cout << endl;

    int dias_primeiro = 0;
    int dias_todos = 0;
    mapa.imprime();
    int n_aeroportos = mapa.contaAeroportos();
    while(n_aeroportos > 0) {
        mapa.calcula_proximo_dia();
        mapa.imprime();
        n_aeroportos = mapa.contaAeroportos();
        if(dias_primeiro == 0 && n_aeroportos < mapa.qtd_aeroportos) {
            dias_primeiro = mapa.dias;
        }
        if(n_aeroportos == 0) {
            dias_todos = mapa.dias;
        }
    }
    cout << "Dias para o 1o aeroporto ficar encoberto........: " << dias_primeiro << endl;
    cout << "Dias para todos os aeroportos ficarem encobertos: " << dias_todos << endl;
}
