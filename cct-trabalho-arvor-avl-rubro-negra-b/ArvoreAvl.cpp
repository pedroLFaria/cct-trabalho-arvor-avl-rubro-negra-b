#include "ArvoreAvl.h"

using namespace ArvoreAvl;

Arvore* ArvoreAvl::criar() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

No* criarNo()
{
    No* no = (No*)malloc(sizeof(No));
    no->pai = NULL;
    no->direita = NULL;
    no->esquerda= NULL;
    return no;
}

int ArvoreAvl::vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

No* ArvoreAvl::adicionarNo(No* no, int valor) {
    if (valor > no->valor) {
        if (no->direita == NULL) {
            printf("Adicionando %d\n", valor);
            No* novo = criarNo();
            novo->valor = valor;
            novo->pai = no;

            no->direita = novo;

            return novo;
        }
        else {
            return adicionarNo(no->direita, valor);
        }
    }
    else {
        if (no->esquerda == NULL) {
            printf("Adicionando %d\n", valor);
            No* novo = criarNo();
            novo->valor = valor;
            novo->pai = no;

            no->esquerda = novo;

            return novo;
        }
        else {
            return adicionarNo(no->esquerda, valor);
        }
    }
}

No* ArvoreAvl::adicionar(Arvore* arvore, int valor) {
    if (arvore->raiz == NULL) {
        printf("Adicionando %d\n", valor);
        No* novo = criarNo();
        novo->valor = valor;

        arvore->raiz = novo;

        return novo;
    }
    else {
        No* no = adicionarNo(arvore->raiz, valor);
        balanceamento(arvore, no);

        return no;
    }
}

void ArvoreAvl::remover(Arvore* arvore, No* no) {
    if (no->esquerda != NULL) {
        remover(arvore, no->esquerda);
    }

    if (no->direita != NULL) {
        remover(arvore, no->direita);
    }

    if (no->pai == NULL) {
        arvore->raiz = NULL;
    }
    else {
        if (no->pai->esquerda == no) {
            no->pai->esquerda = NULL;
        }
        else {
            no->pai->direita = NULL;
        }
    }

    free(no);
}

No* ArvoreAvl::localizar(No* no, int valor) {
    if (no->valor == valor) {
        return no;
    }
    else {
        if (valor < no->valor) {
            if (no->esquerda != NULL) {
                return localizar(no->esquerda, valor);
            }
        }
        else {
            if (no->direita != NULL) {
                return localizar(no->direita, valor);
            }
        }
    }

    return NULL;
}

void ArvoreAvl::percorrerProfundidadeInOrder(No* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrder(no->esquerda, callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(no->direita, callback);
    }
}

void ArvoreAvl::percorrerProfundidadePreOrder(No* no, void (*callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrerProfundidadePreOrder(no->esquerda, callback);
        percorrerProfundidadePreOrder(no->direita, callback);
    }
}

void ArvoreAvl::percorrerProfundidadePosOrder(No* no, void (callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadePosOrder(no->esquerda, callback);
        percorrerProfundidadePosOrder(no->direita, callback);
        callback(no->valor);
    }
}

void ArvoreAvl::visitar(int valor) {
    printf("%d ", valor);
}

void ArvoreAvl::balanceamento(Arvore* arvore, No* no) {
    while (no != NULL) {
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                printf("RSD(%d)\n", no->valor);
                rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            }
            else {
                printf("RDD(%d)\n", no->valor);
                rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        }
        else if (fator < -1) { //árvore mais pesada para a direita
         //rotação para a esquerda
            if (fb(no->direita) < 0) {
                printf("RSE(%d)\n", no->valor);
                rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            }
            else {
                printf("RDE(%d)\n", no->valor);
                rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai;
    }
}

int ArvoreAvl::altura(No* no) {
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int ArvoreAvl::fb(No* no) {
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda - direita;
}

No* ArvoreAvl::rse(Arvore* arvore, No* no) {
    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    }
    else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        }
        else {
            pai->direita = direita;
        }
    }

    return direita;
}

No* ArvoreAvl::rsd(Arvore* arvore, No* no) {
    No* pai = no->pai;
    No* esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    }
    else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        }
        else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

No* ArvoreAvl::rde(Arvore* arvore, No* no) {
    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

No* ArvoreAvl::rdd(Arvore* arvore, No* no) {
    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}