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
        struct No* pai = NULL;
        struct No* esquerda = NULL;
        struct No* direita = NULL;
        Cor cor;
        int valor;
    };

    class Arvore
    {
    public:
        struct No* raiz = NULL;
        struct No* nulo = NULL;
        static Arvore* criar();
        static void visitar(int);
        int vazia();
        No* adicionar(int);
        No* localizar(int valor);
        void percorrerProfundidadeInOrder(No*, void (*)(int));
        void percorrerProfundidadePreOrder(No*, void (*)(int));
        void percorrerProfundidadePosOrder(No*, void (*)(int));
    private:
        No* criarNo(No* pai, int valor);
        No* adicionarNo(No* no, int valor);
        void rotacionarEsquerda(No* no);
        void rotacionarDireita(No* no);
        void balancear(No* no);
    };
}
