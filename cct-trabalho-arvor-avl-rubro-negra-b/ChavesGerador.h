#pragma once
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <set>
#include <iostream>

class ChavesGerador
{
public:
	static std::vector<int> gerarChavesEmOrdemCrescente(int tamanho, int maxValue);
	static std::vector<int> gerarChavesEmOrdemDecrescente(int tamanho, int maxValue);
	static std::vector<int> gerarChavesAleatoria(int tamanho, int maxValue);
};