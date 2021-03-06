#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../cct-trabalho-arvor-avl-rubro-negra-b/ChavesGerador.cpp"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeradorChavesTest
{
	TEST_CLASS(Test)
	{
	public:
		TEST_METHOD(estanciar) {
			ChavesGerador* geradorChaves = new ChavesGerador();
			Assert::IsNotNull(geradorChaves);
		}
		TEST_METHOD(GerarChavesEmOrdemCrescente)
		{
			size_t chavesLenght = 1000;

			
			std::vector<int> chaves = ChavesGerador::gerarChavesEmOrdemCrescente(chavesLenght , 1000);
			Assert::AreEqual(chavesLenght, chaves.size());
			int valorAnterior = -1;
			for (int i : chaves) {
				Assert::IsTrue(i > valorAnterior);
				valorAnterior = i;
			}
		}
		TEST_METHOD(GerarChavesEmOrdemDecrescente)
		{
			size_t chavesLenght = 100;
			std::vector<int> chaves = ChavesGerador::gerarChavesEmOrdemDecrescente(chavesLenght, 1000);
			Assert::AreEqual(chavesLenght, chaves.size());
			int valorAnterior = INT_MAX;
			for (int i : chaves) {
				Assert::IsTrue(i < valorAnterior);
				valorAnterior = i;
			}
		}
		TEST_METHOD(GerarChavesEmOrdemAleatoria)
		{
			size_t chavesLenght = 100;
			std::vector<int> chaves = ChavesGerador::gerarChavesAleatoria(chavesLenght, 1000);
			Assert::AreEqual(chavesLenght, chaves.size());
			int valorAnterior = -1;
			for (int i : chaves) {
				Assert::IsTrue(i != valorAnterior);
				valorAnterior = i;
			}
		}
		TEST_METHOD(DezConjuntosDeMilChaves) {
			std::vector<std::vector<int>>* conjuntoChaves = new std::vector<std::vector<int>>();
			for (int k = 0; k < 9; k++) {
				conjuntoChaves->push_back(ChavesGerador::gerarChavesEmOrdemCrescente(1000, 1000));
			}
			for (int k = 0; k < 9; k++) {
				for (int i : conjuntoChaves->at(k)) {
					visitarLogger(i);
				}
			}
		}
	};
}