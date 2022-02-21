#include <iostream>
#include "ArvoreAvl.h"
#include "ArvoreRubroNegra.h"
#include "ArvoreB.h"
#include "ChavesGerador.h"
#include "CsvGerador.h"

vector<string> gerarEsforcoComputacionalArvore(vector<int> , int , string );

int main()
{
    vector<int> chaves = ChavesGerador::gerarChavesAleatoria(100, 1000);
    gerarEsforcoComputacionalArvore(chaves, 10, "Em ordem aletatoria");

    chaves = ChavesGerador::gerarChavesEmOrdemCrescente(1000, 1000);
    gerarEsforcoComputacionalArvore(chaves, 1, "Em ordem crescente");

    chaves = ChavesGerador::gerarChavesEmOrdemDecrescente(1000, 1000);
    gerarEsforcoComputacionalArvore(chaves, 1, "Em ordem decrescente");
}

vector<string> gerarEsforcoComputacionalArvore(vector<int> chaves, int quantidadeConjuntoTeste, string extensaoNomeArquivo) {
    vector<string> nomesArquivos;

    for (int i = 1; i <= quantidadeConjuntoTeste; i++) {
        ArvoreAvl::Arvore* arvoreAvl = new ArvoreAvl::Arvore();
        ArvoreB::Arvore* arvoreB = new ArvoreB::Arvore(20);
        ArvoreRubroNegra::Arvore* arvoreRubroNegra = new ArvoreRubroNegra::Arvore();
        map<string, vector<string>> estaticas;
        string nomeArquivo = "Esforco computacional " + extensaoNomeArquivo + " " + to_string(i);

        int numeroNo = 1;
        for (int chave : chaves) {
            arvoreAvl->adicionar(chave);
            arvoreB->adicionaChave(chave);
            arvoreRubroNegra->adicionar(chave);

            estaticas["numero de nos"].push_back(to_string(numeroNo));
            estaticas["AVL"].push_back(to_string(arvoreAvl->esforcoComputacional));
            estaticas["B"].push_back(to_string(arvoreB->esforcoComputacional));
            estaticas["Rubro Negra"].push_back(to_string(arvoreRubroNegra->esforcoComputacional));            
            numeroNo++;
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticas);
        arvoreB->limpar();
        arvoreRubroNegra->remover(arvoreRubroNegra->raiz);
    }
    return nomesArquivos;
}