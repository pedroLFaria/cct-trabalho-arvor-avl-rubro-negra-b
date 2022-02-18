#include "ArvoreB.h"

using namespace ArvoreB;

Arvore* Arvore::criaArvore(int ordem) {
    Arvore* a = (Arvore*)malloc(sizeof(Arvore));
    a->ordem = ordem;
    a->raiz = a->criaNo();

    return a;
}

No* Arvore::criaNo() {    
    int max = this->ordem * 2;
    No* no = (No*)malloc(sizeof(No));
    
    no->chaves = (int*)malloc(sizeof(int) * (max + 1));
    no->filhos = (No**)malloc(sizeof(No) * (max + 2));
    no->total = 0;

    for (int i = 0; i < max + 2; i++)
        no->filhos[i] = NULL;

    return no;
}

void Arvore::percorreArvore(No* no) {
    if (no != NULL) {
        for (int i = 0; i < no->total; i++) {
            percorreArvore(no->filhos[i]); //visita o filho a esquerda

            printf("%d ", no->chaves[i]);
        }

        percorreArvore(no->filhos[no->total]); //visita ultimo filho (direita)
    }
}

int Arvore::pesquisaBinaria(No* no, int chave) {
    int inicio = 0, fim = no->total - 1, meio;

    while (inicio <= fim) {
        contador++;

        meio = (inicio + fim) / 2;

        if (no->chaves[meio] == chave) {
            return meio; //encontrou	
        }
        else if (no->chaves[meio] > chave) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    return inicio; //não encontrou	
}

int Arvore::localizaChave(int chave) {
    No* no = this->raiz;

    while (no != NULL) {
        int i = pesquisaBinaria(no, chave);

        if (i < no->total && no->chaves[i] == chave) {
            return 1; //encontrou
        }
        else {
            no = no->filhos[i];
        }
    }

    return 0; //não encontrou	
}

No* Arvore::localizaNo(int chave) {
    No* no = this->raiz;

    while (no != NULL) {
        contador++;

        int i = pesquisaBinaria(no, chave);

        if (no->filhos[i] == NULL)
            return no; //encontrou nó
        else
            no = no->filhos[i];
    }

    return NULL; //não encontrou nenhum nó
}

void Arvore::adicionaChaveNo(No* no, No* novo, int chave) {
    int i = pesquisaBinaria(no, chave);

    contador++;

    for (int j = no->total - 1; j >= i; j--) {
        no->chaves[j + 1] = no->chaves[j];
        no->filhos[j + 2] = no->filhos[j + 1];
    }

    no->chaves[i] = chave;
    no->filhos[i + 1] = novo;

    no->total++;
}

int Arvore::transbordo(No* no) {
    contador++;

    return no->total > this->ordem * 2;
}

No* Arvore::divideNo(No* no) {
    int meio = no->total / 2;
    No* novo = criaNo();
    novo->pai = no->pai;

    contador++;

    for (int i = meio + 1; i < no->total; i++) {
        novo->filhos[novo->total] = no->filhos[i];
        novo->chaves[novo->total] = no->chaves[i];
        if (novo->filhos[novo->total] != NULL) novo->filhos[novo->total]->pai = novo;

        novo->total++;
    }

    novo->filhos[novo->total] = no->filhos[no->total];
    if (novo->filhos[novo->total] != NULL) novo->filhos[novo->total]->pai = novo;
    no->total = meio;
    return novo;
}

void Arvore::adicionaChaveRecursivo(No* no, No* novo, int chave) {
    contador++;

    adicionaChaveNo(no, novo, chave);

    if (transbordo(no)) {
        int promovido = no->chaves[this->ordem];
        No* novo = divideNo(no);

        if (no->pai == NULL) {
            contador++;

            No* pai = criaNo();
            pai->filhos[0] = no;
            adicionaChaveNo(pai, novo, promovido);

            no->pai = pai;
            novo->pai = pai;
            this->raiz = pai;
        }
        else
            adicionaChaveRecursivo(no->pai, novo, promovido);
    }
}

void Arvore::adicionaChave(int chave) {
    No* no = localizaNo(chave);

    adicionaChaveRecursivo(no, NULL, chave);
}