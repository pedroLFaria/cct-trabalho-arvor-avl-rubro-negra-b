#include "CsvGerador.h"
#include <filesystem>

void CsvGerador::gerarCsv(string nomeArquivo, map<string, vector<string>> conteudo) {
	criarDiretorio();
	ofstream arquivo("out\\" + nomeArquivo + ".csv");
	vector<string> cabecalho = getCabecalho(conteudo);
	vector<string> linhas = getLinhas(cabecalho, conteudo);

	std::copy(cabecalho.begin(), cabecalho.end() - 1,
		std::ostream_iterator<string>(arquivo, ";"));
	arquivo << cabecalho.back() + "\n";

	std::copy(linhas.begin(), linhas.end() - 1,
		std::ostream_iterator<string>(arquivo));
	arquivo << linhas.back();
	arquivo.close();
}

void CsvGerador::criarDiretorio() {
	if (!filesystem::exists("out\\"))
		filesystem::create_directory("out\\");
}

vector<string> CsvGerador::getCabecalho(map<string, vector<string>> conteudo) {
	vector<string> cabecalho;
	for (auto const& it : conteudo) {
		cabecalho.push_back(it.first);
	}
	return cabecalho;
}

vector<string> CsvGerador::getLinhas(vector<string> cabecalho, map<string, vector<string>> conteudo) {
	int tamanhoConteudo = conteudo.at(cabecalho.front()).size();
	vector<string> linhas;

	for (int i = 0; i < tamanhoConteudo; i++) {
		string linha;
		for (string it : cabecalho) {
			if (linha.empty())
				linha.append(conteudo.at(it).at(i));
			else
				linha.append(";" + conteudo.at(it).at(i));
		}
		linha.append("\n");
		linhas.push_back(linha);
	}
	return linhas;
}
