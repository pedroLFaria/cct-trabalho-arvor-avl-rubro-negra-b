#pragma once
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include<filesystem>

namespace fs = std::experimental::filesystem;
using namespace std;
class CsvGerador
{
public:
	static void gerarCsv(string nomeArquivo, map<string, vector<string>>);
private:
	static vector<string> getCabecalho(map<string, vector<string>> conteudo);
	static vector<string> getLinhas(vector<string> cabecalho, map<string, vector<string>> conteudo);
	static void criarDiretorio();
};