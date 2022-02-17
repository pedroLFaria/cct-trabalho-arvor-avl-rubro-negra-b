#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../cct-trabalho-arvor-avl-rubro-negra-b/ArvoreRubroNegra.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArvoreRubroNegra;

void visitarLogger(int valor) {
	Logger::WriteMessage(std::to_string(valor).c_str());	
	Logger::WriteMessage("\n");
	Assert::IsTrue(valor > 0);
}
namespace ArvoreRubroNegraTest
{
	TEST_CLASS(Test)
	{
	public:
		Arvore* arvore;
		TEST_METHOD_INITIALIZE(Inicilizar) {
			arvore = criar();
			for (int i = 1; i <= 7; i++) {
				adicionar(arvore, i);
			}
		}
		TEST_METHOD(Criar)
		{
			Arvore* arvore = criar();
			Assert::IsNotNull(arvore);
			Assert::IsNull(arvore->raiz);
		}
		TEST_METHOD(Vazio)
		{
			Arvore* arvore = criar();
			Assert::IsTrue(vazia(arvore));
		}
		TEST_METHOD(Adicionar)
		{
			Assert::IsFalse(vazia(arvore));
		}
		TEST_METHOD(LocalizarNo)
		{
			adicionar(arvore, 55);
			No* no = localizar(arvore, 55);
			Assert::IsNotNull(no);
			Assert::AreEqual(no->valor, 55);
		}
		TEST_METHOD(LocalizarNoFail)
		{
			No* no = localizar(arvore, 55);
			Assert::IsNull(no);
		}
		TEST_METHOD(PercorrerProfundidade)
		{
			percorrerProfundidadeInOrder(arvore, arvore->raiz, visitarLogger);
			percorrerProfundidadePreOrder(arvore, arvore->raiz, visitarLogger);
			percorrerProfundidadePosOrder(arvore, arvore->raiz, visitarLogger);
		}
	};
}