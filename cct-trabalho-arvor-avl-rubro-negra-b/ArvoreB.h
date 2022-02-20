#include <stdio.h>
#include <stdlib.h>

namespace ArvoreB
{
    class No 
    {
    public:
        int total;
        int* chaves;
        No** filhos = NULL;
        No* pai = NULL;
    };

    class Arvore
    {
    public:
        No* raiz = NULL;
        int ordem;
        int contador = 0;
        int esforcoComputacional = 0;

        static Arvore* criaArvore(int);
        void percorreArvore(No*);        
        int pesquisaBinaria(No*, int);
        int localizaChave(int);
        No* localizaNo(int);
        void adicionaChaveNo(No*, No*, int);
        int transbordo(No*);
        No* divideNo(No*);
        void adicionaChaveRecursivo(No*, No*, int);
        void adicionaChave(int);
    private:
        No* criaNo();
    };
}