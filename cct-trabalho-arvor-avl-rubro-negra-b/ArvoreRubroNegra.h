#include <stdlib.h>
#include <stdio.h>

namespace ArvoreRubroNegra
{

    typedef enum coloracao 
    { 
        Vermelho, 
        Preto 
    } Cor;


    typedef struct no 
    {
        struct no* pai;
        struct no* esquerda;
        struct no* direita;
        Cor cor;
        int valor;
    } No;

    typedef struct arvore 
    {
        struct no* raiz;
        struct no* nulo;
    } Arvore;

    Arvore* criar();
    int vazia(Arvore*);
    No* adicionar(Arvore*, int);
    No* localizar(Arvore* arvore, int valor);
    void percorrerProfundidadeInOrder(Arvore*, No*, void (*)(int));
    void percorrerProfundidadePreOrder(Arvore*, No*, void (*)(int));
    void percorrerProfundidadePosOrder(Arvore*, No*, void (*)(int));
    void visitar(int );
}
