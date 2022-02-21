#include "ChavesGerador.h"

std::vector<int> ChavesGerador::gerarChavesEmOrdemCrescente(int tamanho, int maxValue) {
	std::set<int> numbers;
	while (numbers.size() < tamanho) {
		numbers.insert(rand() % 1000);
	}	
	int d = 0;
	for (auto i : numbers) {
		d = d++;
	}	
	std::vector <int> output;
	std::copy(numbers.begin(), numbers.end(), std::back_inserter(output));
	return output;
}

std::vector<int> ChavesGerador::gerarChavesEmOrdemDecrescente(int tamanho, int maxValue) {
	std::vector <int> output = gerarChavesEmOrdemCrescente(tamanho, maxValue);
	std::reverse(output.begin(), output.end());
	return output;
}

std::vector<int> ChavesGerador::gerarChavesAleatoria(int tamanho, int maxValue) {
	std::vector <int> output = gerarChavesEmOrdemCrescente(tamanho, maxValue);
	auto rng = std::default_random_engine{};
	std::shuffle(output.begin(), output.end(), rng);
	return output;
}