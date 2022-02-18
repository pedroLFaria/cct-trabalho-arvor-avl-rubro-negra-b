#include <stdio.h>
#include <stdlib.h>

class No {
public:
    int total;
    int* chaves;
    No** filhos = NULL;
    No* pai = NULL;
};

class ArvoreB
{
public:
    No* raiz = NULL;
    int ordem;
    int contador = 0;

    static ArvoreB* criaArvoreB(int);
    void percorreArvoreB(No*);
    No* criaNo();
    int pesquisaBinaria(No*, int);
    int localizaChave(int);
    No* localizaNo(int);
    void adicionaChaveNo(No*, No*, int);
    int transbordo(No*);
    No* divideNo(No*);
    void adicionaChaveRecursivo(No*, No*, int);
    void adicionaChave(int);

};