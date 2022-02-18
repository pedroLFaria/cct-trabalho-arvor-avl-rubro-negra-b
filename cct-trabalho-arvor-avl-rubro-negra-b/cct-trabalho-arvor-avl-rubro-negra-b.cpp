#include <iostream>
#include "ArvoreAvl.h"
#include "ArvoreRubroNegra.h"
#include "ArvoreB.h"

int main()
{
    std::cout << "Hello World!\n";
    ArvoreAvl::Arvore* aAvl = ArvoreAvl::Arvore::criar();

    for (int i = 1; i <= 7; i++) {
        aAvl->adicionar(i);
    }

    printf("In-order: ");
    aAvl->percorrerProfundidadeInOrder(aAvl->raiz, aAvl->visitar);
    printf("\n");

    ArvoreRubroNegra::Arvore* arn = ArvoreRubroNegra::Arvore::criar();

    arn->adicionar(7);
    arn->adicionar(6);
    arn->adicionar(5);
    arn->adicionar(4);
    arn->adicionar(3);
    arn->adicionar(2);
    arn->adicionar(1);

    printf("In-order: ");
    arn->percorrerProfundidadeInOrder(arn->raiz, arn->visitar);
    printf("\n");

    ArvoreB::Arvore* arvoreB = ArvoreB::Arvore::criaArvore(1);

    arvoreB->adicionaChave(12);
    arvoreB->adicionaChave(3);
    arvoreB->adicionaChave(5);
    arvoreB->adicionaChave(7);
    arvoreB->adicionaChave(15);
    arvoreB->adicionaChave(99);
    arvoreB->adicionaChave(1);

    arvoreB->percorreArvore(arvoreB->raiz);

    printf("\nNúmero de operações: %d\n", arvoreB->contador);
}
