#include <iostream>
#include "ArvoreAvl.h"
#include "ArvoreRubroNegra.h"

int main()
{
    std::cout << "Hello World!\n";
    ArvoreAvl::Arvore* aAvl = ArvoreAvl::criar();

    for (int i = 1; i <= 7; i++) {
        ArvoreAvl::adicionar(aAvl, i);
    }

    printf("In-order: ");
    percorrerProfundidadeInOrder(aAvl->raiz, ArvoreAvl::visitar);
    printf("\n");

    ArvoreRubroNegra::Arvore* arn = ArvoreRubroNegra::criar();

    adicionar(arn, 7);
    adicionar(arn, 6);
    adicionar(arn, 5);
    adicionar(arn, 4);
    adicionar(arn, 3);
    adicionar(arn, 2);
    adicionar(arn, 1);

    printf("In-order: ");
    ArvoreRubroNegra::percorrerProfundidadeInOrder(arn, arn->raiz, ArvoreRubroNegra::visitar);
    printf("\n");
}
