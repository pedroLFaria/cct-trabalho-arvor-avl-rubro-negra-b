#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../cct-trabalho-arvor-avl-rubro-negra-b/ArvoreB.cpp"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArvoreB;

namespace ArvoreBTest
{
	TEST_CLASS(Test)
	{
	public:
		Arvore* arvore;
		TEST_METHOD_INITIALIZE(Inicilizar) {
			arvore = Arvore::criaArvore(1);
			for (int i = 1; i <= 7; i++) {
				arvore->adicionaChave(i);
			}
		}
		TEST_METHOD(criaArvore)
		{
			Arvore* arvore = Arvore::criaArvore(1);
			Assert::IsNotNull(arvore);
			Assert::IsNotNull(arvore->raiz);
		}
		TEST_METHOD(percorreArvore)
		{
			arvore->percorreArvore(arvore->raiz);			
		}
	};
}