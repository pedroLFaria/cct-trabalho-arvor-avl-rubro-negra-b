#include <stdlib.h>
#include <stdio.h>
namespace ArvoreAvl
{
    typedef struct no 
    {
        struct no* pai;
        struct no* esquerda;
        struct no* direita;
        int valor;
    } No;

    typedef struct arvore 
    {
        struct no* raiz;
    } Arvore;

    Arvore* criar();
    int vazia(Arvore*);
    No* adicionarNo(No*, int);
    No* adicionar(Arvore*, int);
    void remover(Arvore*, No* );
    No* localizar(No*, int );
    void percorrerProfundidadeInOrder(No*, void (*callback)(int));
    void percorrerProfundidadePreOrder(No*, void (*callback)(int));
    void percorrerProfundidadePosOrder(No*, void (callback)(int));
    void visitar(int );
    void balanceamento(Arvore*, No*);
    int altura(No*);
    int fb(No*);
    No* rsd(Arvore*, No*);
    No* rse(Arvore*, No*);
    No* rdd(Arvore*, No*);
    No* rde(Arvore*, No*);
}