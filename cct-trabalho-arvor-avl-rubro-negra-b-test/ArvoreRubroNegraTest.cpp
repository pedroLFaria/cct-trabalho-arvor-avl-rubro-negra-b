#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../cct-trabalho-arvor-avl-rubro-negra-b/ArvoreRubroNegra.cpp"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArvoreRubroNegra;

namespace ArvoreRubroNegraTest
{
	TEST_CLASS(Test)
	{
	public:
		Arvore* arvore;
		TEST_METHOD_INITIALIZE(Inicilizar) {
			arvore = Arvore::criar();
			for (int i = 1; i <= 7; i++) {
				arvore->adicionar(i);
			}
		}
		TEST_METHOD(Criar)
		{
			Arvore* arvore = Arvore::criar();
			Assert::IsNotNull(arvore);
			Assert::IsNull(arvore->raiz);
		}
		TEST_METHOD(Vazio)
		{
			Arvore* arvore = Arvore::criar();
			Assert::IsTrue(arvore->vazia());
		}
		TEST_METHOD(Adicionar)
		{
			Assert::IsFalse(arvore->vazia());
		}
		TEST_METHOD(LocalizarNo)
		{
			arvore->adicionar(55);
			No* no = arvore->localizar(55);
			Assert::IsNotNull(no);
			Assert::AreEqual(no->valor, 55);
		}
		TEST_METHOD(LocalizarNoFail)
		{
			No* no = arvore->localizar(55);
			Assert::IsNull(no);
		}
		TEST_METHOD(PercorrerProfundidade)
		{
			arvore->percorrerProfundidadeInOrder(arvore->raiz, visitarLogger);
			arvore->percorrerProfundidadePreOrder(arvore->raiz, visitarLogger);
			arvore->percorrerProfundidadePosOrder(arvore->raiz, visitarLogger);
		}
	};
}