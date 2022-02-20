#include <iostream>
#include "ArvoreAvl.h"
#include "ArvoreRubroNegra.h"
#include "ArvoreB.h"
#include "ChavesGerador.h"
#include "CsvGerador.h"

vector<string> gerarEsforcoComputacionalArvoreAvl();
vector<string> gerarEsforcoComputacionalArvoreB();
vector<string> gerarEsforcoComputacionalArvoreRubroNegra();

int main()
{
    vector<string> arquivosAvl = gerarEsforcoComputacionalArvoreAvl();
    vector<string> arquivosB = gerarEsforcoComputacionalArvoreB();
    vector<string> arquivosRubroNegra = gerarEsforcoComputacionalArvoreRubroNegra();
}

vector<string> gerarEsforcoComputacionalArvoreAvl() {    
    vector<string> nomesArquivos;

    for(int i = 1; i <= 10; i++){
        ArvoreAvl::Arvore* arvore = new ArvoreAvl::Arvore();
        map<string, vector<string>> estaticasAvl;
        string nomeArquivo = "Arvore Avl" + to_string(i);
        vector<string> esforcoComputacional;
        vector<string> numeroNos;

        for (int i = 1; i <= 1000; i++) {
            arvore->adicionar(i);
            estaticasAvl["esforcoComputacional"].push_back(to_string(arvore->esforcoComputacional));
            estaticasAvl["numeroNos"].push_back(to_string(i));
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticasAvl);
        delete arvore;
    }
    return nomesArquivos;
}

vector<string> gerarEsforcoComputacionalArvoreB() {    
    vector<string> nomesArquivos;

    for (int i = 1; i <= 10; i++) {
        ArvoreB::Arvore* arvore = new ArvoreB::Arvore(20);
        map<string, vector<string>> estaticasAvl;
        string nomeArquivo = "Arvore B" + to_string(i);
        vector<string> esforcoComputacional;
        vector<string> numeroNos;

        for (int i = 1; i <= 1000; i++) {
            arvore->adicionaChave(i);
            estaticasAvl["esforcoComputacional"].push_back(to_string(arvore->esforcoComputacional));
            estaticasAvl["numeroNos"].push_back(to_string(i));
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticasAvl);
        delete arvore;
    }
    return nomesArquivos;
}

vector<string> gerarEsforcoComputacionalArvoreRubroNegra() {    
    vector<string> nomesArquivos;

    for (int i = 1; i <= 10; i++) {
        ArvoreRubroNegra::Arvore* arvore = new ArvoreRubroNegra::Arvore();
        map<string, vector<string>> estaticasAvl;
        string nomeArquivo = "Arvore Rubro Negra" + to_string(i);
        vector<string> esforcoComputacional;
        vector<string> numeroNos;

        for (int i = 1; i <= 1000; i++) {
            arvore->adicionar(i);
            estaticasAvl["esforcoComputacional"].push_back(to_string(arvore->esforcoComputacional));
            estaticasAvl["numeroNos"].push_back(to_string(i));
        }
        nomesArquivos.push_back(nomeArquivo);
        CsvGerador::gerarCsv(nomeArquivo, estaticasAvl);
        delete arvore;
    }
    return nomesArquivos;
}