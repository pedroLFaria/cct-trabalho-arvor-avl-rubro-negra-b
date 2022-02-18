#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../cct-trabalho-arvor-avl-rubro-negra-b/ArvoreAvl.cpp"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArvoreAvlTest
{
	TEST_CLASS(Test)
	{
	public:
		Arvore* arvore;
		TEST_METHOD_INITIALIZE(avlTreeInicialization){
			arvore = Arvore::criar();
			for (int i = 1; i <= 7; i++) {
				arvore->adicionar(i);
			}
		}
		TEST_METHOD(avlTreeCriar)
		{
			Arvore* arvore = Arvore::criar();
			Assert::IsNotNull(arvore);
			Assert::IsNull(arvore->raiz);
		}		
		TEST_METHOD(avlTreeVazio)
		{
			Arvore* arvore = Arvore::criar();
			Assert::IsTrue(arvore->vazia());			
		}
		TEST_METHOD(avlTreeAdicionar)
		{
			Assert::IsFalse(arvore->vazia());
		}
		TEST_METHOD(avlTreeLocalizarNo)
		{
			arvore->adicionar(55);
			No* no = arvore->localizar(arvore->raiz, 55);
			Assert::IsNotNull(no);
			Assert::AreEqual(no->valor, 55);
		}
		TEST_METHOD(avlTreeLocalizarNoFail)
		{
			No* no = arvore->localizar(arvore->raiz, 55);
			Assert::IsNull(no);
		}
		TEST_METHOD(avlTreeAltura)
		{
			int alturaArvore = arvore->altura(arvore->raiz);
			Assert::AreEqual(2, alturaArvore);
		}
		TEST_METHOD(avlTreefb)
		{
			int fbArvore = arvore->fb(arvore->raiz);
			Assert::AreEqual(0,fbArvore);
		}
		TEST_METHOD(avlTreePercorrerProfundidade)
		{
			arvore->percorrerProfundidadeInOrder(arvore->raiz, visitarLogger);
			arvore->percorrerProfundidadePreOrder(arvore->raiz, visitarLogger);
			arvore->percorrerProfundidadePosOrder(arvore->raiz, visitarLogger);
		}
		TEST_METHOD(avlTreeBalanceamento) {
			Arvore* arvore = arvore->criar();
			arvore->adicionar(7);
			arvore->adicionar(1);
			arvore->adicionar(2);
			int fbArvore = arvore->fb(arvore->raiz);
			Assert::IsTrue(fbArvore == 2);
			arvore->balanceamento(arvore->raiz);
			fbArvore = arvore->fb(arvore->raiz);
			Assert::IsTrue(fbArvore == 0);
		}		
	};
}