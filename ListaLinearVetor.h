#ifndef _LISTA_LINEAR_VETOR_H_
#define _LISTA_LINEAR_VETOR_H_

template <typename T>
struct Lista {
    int N, MAX;
    T *vetor;

    Lista(int max)
    {
        MAX = max;
        N = 0;
        vetor = new T[MAX];
    }

    ~Lista()
    {
        delete[] vetor;
    }

    bool insere(T elemento)
    {
        bool sucesso = false;

        if(N < MAX) {
            vetor[N] = elemento;
            N++;
            sucesso = true;
        }

        return sucesso;
    }

    void atualiza(int indice, T elemento)
    {
        if(indice >= 0 && indice < N) {
            vetor[indice] = elemento;
        }
    }

    void remover(int indice)
    {
        if(indice >= 0 && indice < N) {
            for(int i = indice; i < N - 1; i++) {
                vetor[i] = vetor[i + 1];
            }
            N--;
        }
    }

    int quantidade()
    {
        return N;
    }

    int capacidade()
    {
        return MAX;
    }

    T acesso(int i)
    {
        return vetor[i];
    }

    bool vazia()
    {
        return N == 0;
    }

    bool cheia()
    {
        return N == MAX;
    }
};

#endif // _LISTA_LINEAR_VETOR_H_
