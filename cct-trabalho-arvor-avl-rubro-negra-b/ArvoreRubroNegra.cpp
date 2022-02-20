#include "ArvoreRubroNegra.h"

using namespace ArvoreRubroNegra;

No* Arvore::criarNo(No* pai, int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->pai = pai;
    no->valor = valor;
    no->direita = this->nulo;
    no->esquerda = this->nulo;

    return no;
}

Arvore::Arvore() {
    this->nulo = this->criarNo(NULL, 0);
    this->nulo->cor = Preto;
}

Arvore* Arvore::criar() {
    Arvore* arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = arvore->criarNo(NULL, 0);
    arvore->nulo->cor = Preto;

    return arvore;
}

int Arvore::vazia() {
    return this->raiz == NULL;
}

No* Arvore::adicionarNo(No* no, int valor) {
    this->esforcoComputacional++;
    if (valor > no->valor) {
        if (no->direita == this->nulo) {
            no->direita = criarNo(no, valor);
            no->direita->cor = Vermelho;

            return no->direita;
        }
        else {
            return adicionarNo(no->direita, valor);
        }
    }
    else {
        if (no->esquerda == this->nulo) {
            no->esquerda = criarNo(no, valor);
            no->esquerda->cor = Vermelho;

            return no->esquerda;
        }
        else {
            return adicionarNo(no->esquerda, valor);
        }
    }
}

No* Arvore::adicionar(int valor) {    
    if (vazia()) {
        this->esforcoComputacional++;
        this->raiz = criarNo(this->nulo, valor);
        this->raiz->cor = Preto;

        return this->raiz;
    }
    else {
        No* no = adicionarNo(this->raiz, valor);
        balancear(no);

        return no;
    }
}

No* Arvore::localizar(int valor) {
    if (!vazia()) {
        No* no = this->raiz;

        while (no != this->nulo) {
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

void Arvore::percorrerProfundidadeInOrder(No* no, void (*callback)(int)) {
    if (no != this->nulo) {
        percorrerProfundidadeInOrder(no->esquerda, callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(no->direita, callback);
    }
}

void Arvore::percorrerProfundidadePreOrder(No* no, void (*callback)(int)) {
    if (no != this->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrder(no->esquerda, callback);
        percorrerProfundidadePreOrder(no->direita, callback);
    }
}

void Arvore::percorrerProfundidadePosOrder(No* no, void (*callback)(int)) {
    if (no != this->nulo) {
        percorrerProfundidadePosOrder(no->esquerda, callback);
        percorrerProfundidadePosOrder(no->direita, callback);
        callback(no->valor);
    }
}

void Arvore::visitar(int valor) {
    printf("%d ", valor);
}

void Arvore::rotacionarEsquerda(No* no) {
    No* direita = no->direita;
    no->direita = direita->esquerda;

    if (direita->esquerda != this->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;

    if (no->pai == this->nulo) {
        this->raiz = direita;
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

void Arvore::balancear(No* no) {
    this->esforcoComputacional++;
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
                    rotacionarEsquerda(no); //Caso 2
                }
                else {
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireita(no->pai->pai); //Caso 3
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
                    rotacionarDireita(no); //Caso 2
                }
                else {
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerda(no->pai->pai); //Caso 3
                }
            }
        }
    }
    this->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void Arvore::rotacionarDireita(No* no) {
    No* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;

    if (esquerda->direita != this->nulo) {
        esquerda->direita->pai = no;
    }

    esquerda->pai = no->pai;

    if (no->pai == this->nulo) {
        this->raiz = esquerda;
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