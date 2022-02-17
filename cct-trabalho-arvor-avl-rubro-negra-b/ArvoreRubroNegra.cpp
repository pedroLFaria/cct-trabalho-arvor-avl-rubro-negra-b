#include "ArvoreRubroNegra.h"

using namespace ArvoreRubroNegra;

No* adicionarNo(Arvore* arvore, No* no, int valor);
void rotacionarEsquerda(Arvore* arvore, No* no);
void rotacionarDireita(Arvore* arvore, No* no);
void balancear(Arvore* arvore, No* no);

No* criarNo(Arvore* arvore, No* pai, int valor) {
    No* no = (No*)malloc(sizeof(No));

    no->pai = pai;
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;

    return no;
}

Arvore* ArvoreRubroNegra::criar() {
    Arvore* arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = criarNo(arvore, NULL, 0);
    arvore->nulo->cor = Preto;

    return arvore;
}

int ArvoreRubroNegra::vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

No* adicionarNo(Arvore* arvore, No* no, int valor) {
    if (valor > no->valor) {
        if (no->direita == arvore->nulo) {
            no->direita = criarNo(arvore, no, valor);
            no->direita->cor = Vermelho;

            return no->direita;
        }
        else {
            return adicionarNo(arvore, no->direita, valor);
        }
    }
    else {
        if (no->esquerda == arvore->nulo) {
            no->esquerda = criarNo(arvore, no, valor);
            no->esquerda->cor = Vermelho;

            return no->esquerda;
        }
        else {
            return adicionarNo(arvore, no->esquerda, valor);
        }
    }
}

No* ArvoreRubroNegra::adicionar(Arvore* arvore, int valor) {
    if (vazia(arvore)) {
        arvore->raiz = criarNo(arvore, arvore->nulo, valor);
        arvore->raiz->cor = Preto;

        return arvore->raiz;
    }
    else {
        No* no = adicionarNo(arvore, arvore->raiz, valor);
        balancear(arvore, no);

        return no;
    }
}

No* ArvoreRubroNegra::localizar(Arvore* arvore, int valor) {
    if (!vazia(arvore)) {
        No* no = arvore->raiz;

        while (no != arvore->nulo) {
            if (no->valor == valor) {
                return no;
            }
            else {
                no = valor < no->valor ? no->esquerda : no->direita;
            }
        }
    }

    return NULL;
}

void ArvoreRubroNegra::percorrerProfundidadeInOrder(Arvore* arvore, No* no, void (*callback)(int)) {
    if (no != arvore->nulo) {


        percorrerProfundidadeInOrder(arvore, no->esquerda, callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita, callback);
    }
}

void ArvoreRubroNegra::percorrerProfundidadePreOrder(Arvore* arvore, No* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrder(arvore, no->esquerda, callback);
        percorrerProfundidadePreOrder(arvore, no->direita, callback);
    }
}

void ArvoreRubroNegra::percorrerProfundidadePosOrder(Arvore* arvore, No* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        percorrerProfundidadePosOrder(arvore, no->esquerda, callback);
        percorrerProfundidadePosOrder(arvore, no->direita, callback);
        callback(no->valor);
    }
}

void ArvoreRubroNegra::visitar(int valor) {
    printf("%d ", valor);
}

void rotacionarEsquerda(Arvore* arvore, No* no) {
    No* direita = no->direita;
    no->direita = direita->esquerda;

    if (direita->esquerda != arvore->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = direita;
    }
    else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    }
    else {
        no->pai->direita = direita;
    }

    direita->esquerda = no;
    no->pai = direita;
}

void balancear(Arvore* arvore, No* no) {
    while (no->pai->cor == Vermelho) {
        if (no->pai == no->pai->pai->esquerda) {
            No* tio = no->pai->pai->direita;

            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto;

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            }
            else {
                if (no == no->pai->direita) {
                    no = no->pai; //Caso 2
                    rotacionarEsquerda(arvore, no); //Caso 2
                }
                else {
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireita(arvore, no->pai->pai); //Caso 3
                }
            }
        }
        else {
            No* tio = no->pai->pai->esquerda;

            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto;

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            }
            else {
                if (no == no->pai->esquerda) {
                    no = no->pai; //Caso 2
                    rotacionarDireita(arvore, no); //Caso 2
                }
                else {
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerda(arvore, no->pai->pai); //Caso 3
                }
            }
        }
    }
    arvore->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotacionarDireita(Arvore* arvore, No* no) {
    No* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;

    if (esquerda->direita != arvore->nulo) {
        esquerda->direita->pai = no;
    }

    esquerda->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = esquerda;
    }
    else if (no == no->pai->esquerda) {
        no->pai->esquerda = esquerda;
    }
    else {
        no->pai->direita = esquerda;
    }

    esquerda->direita = no;
    no->pai = esquerda;
}