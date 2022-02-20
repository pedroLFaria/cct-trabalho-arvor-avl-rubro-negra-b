#include "pch.h"
#include "CppUnitTest.h"
#include "../cct-trabalho-arvor-avl-rubro-negra-b/CsvGerador.cpp"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeradorChavesTest
{
	TEST_CLASS(Test)
	{
	public:
		TEST_METHOD(estanciar) {
			CsvGerador* csvGerador = new CsvGerador();
			Assert::IsNotNull(csvGerador);
		}
		TEST_METHOD(gerarCsvTst) {
			map<string, vector<string>> testeUnitario;
			testeUnitario["teste"] = { "1", "2" };
			testeUnitario["unitario"] = { "3", "4" };
			CsvGerador::gerarCsv((string)"testeUnitario", testeUnitario);
			ifstream arquivo("testeUnitario.csv");
			string actual;
			std::getline(arquivo, actual);
			Assert::AreEqual((string)"teste;unitario", actual);
			std::getline(arquivo, actual);
			Assert::AreEqual((string)"1;3", actual);
			std::getline(arquivo, actual);
			Assert::AreEqual((string)"2;4", actual);
		}
	};
}