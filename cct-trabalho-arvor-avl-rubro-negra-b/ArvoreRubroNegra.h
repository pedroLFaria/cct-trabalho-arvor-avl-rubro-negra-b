#include <stdlib.h>
#include <stdio.h>

namespace ArvoreRubroNegra
{

    typedef enum coloracao 
    { 
        Vermelho, 
        Preto 
    } Cor;


    class No
    {
    public:
        No* pai = NULL;
        No* esquerda = NULL;
        No* direita = NULL;
        Cor cor;
        int valor;
    };

    class Arvore
    {
    public:
        No* raiz = NULL;
        No* nulo = NULL;
        int esforcoComputacional = 0;

        Arvore();
        static Arvore* criar();
        static void visitar(int);
        int vazia();
        No* adicionar(int);
        No* localizar(int valor);
        void percorrerProfundidadeInOrder(No*, void (*)(int));
        void percorrerProfundidadePreOrder(No*, void (*)(int));
        void percorrerProfundidadePosOrder(No*, void (*)(int));
        void remover(No* no);
    private:
        No* criarNo(No* pai, int valor);
        No* adicionarNo(No* no, int valor);
        void rotacionarEsquerda(No* no);
        void rotacionarDireita(No* no);
        void balancear(No* no);
    };
}
