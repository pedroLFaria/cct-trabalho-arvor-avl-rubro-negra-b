#include <stdlib.h>
#include <stdio.h>

namespace ArvoreAvl
{

    class No 
    {
    public:
        No* pai = NULL;
        No* esquerda = NULL;
        No* direita = NULL;
        int valor = NULL;
    };

    class Arvore
    {
    public:
        struct No* raiz = NULL;
        static Arvore* criar();
        int vazia();
        No* adicionarNo(No*, int);
        No* adicionar(int);
        void remover(No*);
        No* localizar(No*, int);
        void percorrerProfundidadeInOrder(No*, void (*callback)(int));
        void percorrerProfundidadePreOrder(No*, void (*callback)(int));
        void percorrerProfundidadePosOrder(No*, void (callback)(int));
        static void visitar(int);
        void balanceamento(No*);
        int altura(No*);
        int fb(No*);
        No* rsd(No*);
        No* rse(No*);
        No* rdd(No*);
        No* rde(No*);
    };
}