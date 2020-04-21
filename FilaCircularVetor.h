#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <typename Tipo>
struct Fila {
private:
    Tipo *v;
    int tamanho;
    int qtde;
    int inic;
    int fim;

public:
    Fila(int tam)
    {
        tamanho = tam;
        v = new Tipo[tamanho];
        qtde = 0;
        fim = -1;
        inic = 0;
    }

    ~Fila()
    {
        delete v;
    }

    void insere(Tipo x)
    {
        fim++;
        if(fim == tamanho) {
            fim = 0;
        }
        v[fim] = x;
        qtde++;
    }

    Tipo remover()
    {
        Tipo temp = v[inic];
        inic++;
        if(inic == tamanho) {
            inic = 0;
        }
        qtde--;
        return temp;
    }

    Tipo primeiro()
    {
        return v[inic];
    }

    bool filaCheia()
    {
        return qtde == tamanho;
    }

    bool filaVazia()
    {
        return qtde == 0;
    }

    int getTamanho()
    {
        return tamanho;
    }

    int getQtde()
    {
        return qtde;
    }

    int getInic()
    {
        return inic;
    }

    int getFim()
    {
        return fim;
    }

    Tipo getValor(int pos)
    {
        // return v[pos];
        return v[(inic + pos) % tamanho];
    }
};

#endif // FILA_H_INCLUDED
