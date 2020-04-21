#ifndef _FILA_VETOR_H_
#define _FILA_VETOR_H_

template <typename T>
struct Fila {
    int N, MAX;
    T *vetor;

    Fila(int max)
    {
        MAX = max;
        N = 0;
        vetor = new T[MAX];
    }

    ~Fila()
    {
        delete[] vetor;
    }

    bool insere(T elemento)
    {
        bool sucesso = false;

        if(N < MAX) {
            vetor[N] = elemento; // na fila, sempre inserimos no final
            N++;
            sucesso = true;
        }

        return sucesso;
    }

    void remover()
    {
        if(N > 0) {
            // na fila, sempre removemos no início
            for(int i = 0; i < N - 1; i++) {
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

    T acesso()
    {
        return acesso(0); // na fila, sempre acessamos o primeiro elemento
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

#endif // _FILA_VETOR_H_
