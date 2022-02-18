#include "ArvoreAvl.h"

using namespace ArvoreAvl;

Arvore* Arvore::criar() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

No* criarNo()
{
    No* no = (No*)malloc(sizeof(No));
    return no;
}

int Arvore::vazia() {
    return this->raiz == NULL;
}

No* Arvore::adicionarNo(No* no, int valor) {
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

No* Arvore::adicionar(int valor) {
    if (this->raiz == NULL) {
        printf("Adicionando %d\n", valor);
        No* novo = criarNo();
        novo->valor = valor;
        this->raiz = novo;
        return novo;
    }
    else {
        No* no = adicionarNo(this->raiz, valor);
        balanceamento(no);
        return no;
    }
}

void Arvore::remover(No* no) {
    if (no->esquerda != NULL) {
        remover(no->esquerda);
    }

    if (no->direita != NULL) {
        remover(no->direita);
    }

    if (no->pai == NULL) {
        this->raiz = NULL;
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

No* Arvore::localizar(No* no, int valor) {
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

void Arvore::percorrerProfundidadeInOrder(No* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrder(no->esquerda, callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(no->direita, callback);
    }
}

void Arvore::percorrerProfundidadePreOrder(No* no, void (*callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrerProfundidadePreOrder(no->esquerda, callback);
        percorrerProfundidadePreOrder(no->direita, callback);
    }
}

void Arvore::percorrerProfundidadePosOrder(No* no, void (callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadePosOrder(no->esquerda, callback);
        percorrerProfundidadePosOrder(no->direita, callback);
        callback(no->valor);
    }
}

void Arvore::visitar(int valor) {
    printf("%d ", valor);
}

void Arvore::balanceamento(No* no) {
    while (no != NULL) {
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                printf("RSD(%d)\n", no->valor);
                rsd(no); //rotação simples a direita, pois o FB do filho tem sinal igual
            }
            else {
                printf("RDD(%d)\n", no->valor);
                rdd(no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        }
        else if (fator < -1) { //árvore mais pesada para a direita
         //rotação para a esquerda
            if (fb(no->direita) < 0) {
                printf("RSE(%d)\n", no->valor);
                rse(no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            }
            else {
                printf("RDE(%d)\n", no->valor);
                rde(no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai;
    }
}

int Arvore::altura(No* no) {
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int Arvore::fb(No* no) {
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda - direita;
}

No* Arvore::rse(No* no) {
    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        this->raiz = direita;
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

No* Arvore::rsd(No* no) {
    No* pai = no->pai;
    No* esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        this->raiz = esquerda;
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

No* Arvore::rde(No* no) {
    no->direita = rsd(no->direita);
    return rse(no);
}

No* Arvore::rdd(No* no) {
    no->esquerda = rse(no->esquerda);
    return rsd(no);
}