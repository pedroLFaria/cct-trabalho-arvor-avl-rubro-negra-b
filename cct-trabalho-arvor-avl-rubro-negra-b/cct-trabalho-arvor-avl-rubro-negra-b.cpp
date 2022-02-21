#include <iostream>
#include "ArvoreAvl.h"
#include "ArvoreRubroNegra.h"
#include "ArvoreB.h"
#include "ChavesGerador.h"
#include "CsvGerador.h"

vector<string> gerarEsforcoComputacionalArvoreAvl(vector<int>, int, string);
vector<string> gerarEsforcoComputacionalArvoreB(vector<int>, int, string);
vector<string> gerarEsforcoComputacionalArvoreRubroNegra(vector<int>, int, string);

int main()
{
    vector<int> chaves = ChavesGerador::gerarChavesAleatoria(100, 1000);
    gerarEsforcoComputacionalArvoreAvl(chaves, 10, "Em ordem aletatoria");

    chaves = ChavesGerador::gerarChavesEmOrdemCrescente(1000, 1000);
    gerarEsforcoComputacionalArvoreAvl(chaves, 1, "Em ordem crescente");
    gerarEsforcoComputacionalArvoreB(chaves, 1, "Em ordem crescente");
    gerarEsforcoComputacionalArvoreRubroNegra(chaves, 1, "Em ordem crescente");

    chaves = ChavesGerador::gerarChavesEmOrdemDecrescente(1000, 1000);
    gerarEsforcoComputacionalArvoreAvl(chaves, 1, "Em ordem decrescente");    
    gerarEsforcoComputacionalArvoreB(chaves, 1, "Em ordem decrescente");
    gerarEsforcoComputacionalArvoreRubroNegra(chaves, 1, "Em ordem decrescente");

    
    chaves = ChavesGerador::gerarChavesAleatoria(1000, 1000);
    gerarEsforcoComputacionalArvoreB(chaves, 10, "Em ordem aletatoria");
    gerarEsforcoComputacionalArvoreRubroNegra(chaves, 10, "Em ordem aletatoria");
}
vector<string> gerarEsforcoComputacionalArvoreAvl(vector<int> chaves, int quantidadeConjuntoTeste, string extensaoNomeArquivo) {
    vector<string> nomesArquivos;

    for(int i = 1; i <= quantidadeConjuntoTeste; i++) {
        ArvoreAvl::Arvore* arvore = new ArvoreAvl::Arvore();
        map<string, vector<string>> estaticasAvl;
        string nomeArquivo = "Arvore Avl " + extensaoNomeArquivo + to_string(i);
        vector<string> esforcoComputacional;
        vector<string> numeroNos;
        int numeroNo = 1;

        for (int i: chaves) {
            arvore->adicionar(i);
            estaticasAvl["esforcoComputacional"].push_back(to_string(arvore->esforcoComputacional));
            estaticasAvl["numeroNos"].push_back(to_string(numeroNo));
            numeroNo++;
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticasAvl);
        delete arvore;
    }
    return nomesArquivos;
}

vector<string> gerarEsforcoComputacionalArvoreB(vector<int> chaves, int quantidadeConjuntoTeste, string extensaoNomeArquivo) {
    vector<string> nomesArquivos;

    for (int i = 1; i <= 10; i++) {
        ArvoreB::Arvore* arvore = new ArvoreB::Arvore(20);
        map<string, vector<string>> estaticasAvl;
        string nomeArquivo = "Arvore B " + extensaoNomeArquivo + to_string(i);
        vector<string> esforcoComputacional;
        vector<string> numeroNos;
        int numeroNo = 1;

        for (int i : chaves) {
            arvore->adicionaChave(i);
            estaticasAvl["esforcoComputacional"].push_back(to_string(arvore->esforcoComputacional));
            estaticasAvl["numeroNos"].push_back(to_string(numeroNo));
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticasAvl);
        arvore->limpar();
        delete arvore;
    }
    return nomesArquivos;
}

vector<string> gerarEsforcoComputacionalArvoreRubroNegra(vector<int> chaves, int quantidadeConjuntoTeste, string extensaoNomeArquivo) {
    vector<string> nomesArquivos;

    for (int i = 1; i <= 10; i++) {
        ArvoreRubroNegra::Arvore* arvore = new ArvoreRubroNegra::Arvore();
        map<string, vector<string>> estaticasAvl;
        string nomeArquivo = "Arvore Rubro Negra " + extensaoNomeArquivo + to_string(i);
        vector<string> esforcoComputacional;
        vector<string> numeroNos;
        int numeroNo = 1;

        for (int i : chaves) {
            arvore->adicionar(i);
            estaticasAvl["esforcoComputacional"].push_back(to_string(arvore->esforcoComputacional));
            estaticasAvl["numeroNos"].push_back(to_string(numeroNo));
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticasAvl);
        arvore->remover(arvore->raiz);
        delete arvore;
    }
    return nomesArquivos;
}