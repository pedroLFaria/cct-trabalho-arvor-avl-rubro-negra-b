#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../cct-trabalho-arvor-avl-rubro-negra-b/ArvoreAvl.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


void visitarLogger(int valor) {
	Logger::WriteMessage(std::to_string(valor).c_str());
	Logger::WriteMessage("\n");
}
namespace ArvoreAvlTest
{
	TEST_CLASS(Test)
	{
	public:
		Arvore* arvore;
		TEST_METHOD_INITIALIZE(avlTreeInicialization){
			arvore = criar();
			for (int i = 1; i <= 7; i++) {
				ArvoreAvl::adicionar(arvore, i);
			}
		}
		TEST_METHOD(avlTreeCriar)
		{
			Arvore* arvore = criar();
			Assert::IsNotNull(arvore);
			Assert::IsNull(arvore->raiz);
		}		
		TEST_METHOD(avlTreeVazio)
		{
			Arvore* arvore = criar();
			Assert::IsTrue(vazia(arvore));			
		}
		TEST_METHOD(avlTreeAdicionar)
		{
			Assert::IsFalse(vazia(arvore));
		}
		TEST_METHOD(avlTreeLocalizarNo)
		{
			adicionar(arvore, 55);
			No* no = localizar(arvore->raiz, 55);
			Assert::IsNotNull(no);
			Assert::AreEqual(no->valor, 55);
		}
		TEST_METHOD(avlTreeLocalizarNoFail)
		{
			No* no = localizar(arvore->raiz, 55);
			Assert::IsNull(no);
		}
		TEST_METHOD(avlTreeAltura)
		{
			int alturaArvore = altura(arvore->raiz);
			Assert::AreEqual(2, alturaArvore);
		}
		TEST_METHOD(avlTreefb)
		{
			int fbArvore = fb(arvore->raiz);
			Assert::AreEqual(0,fbArvore);
		}
		TEST_METHOD(avlTreePercorrerProfundidade)
		{
			percorrerProfundidadeInOrder(arvore->raiz, visitarLogger);
			percorrerProfundidadePreOrder(arvore->raiz, visitar);
			percorrerProfundidadePosOrder(arvore->raiz, visitarLogger);
		}
		TEST_METHOD(avlTreeBalanceamento) {
			Arvore* arvore = criar();
			adicionar(arvore, 7);
			adicionar(arvore, 1);
			adicionar(arvore, 2);
			int fbArvore = fb(arvore->raiz);
			Assert::IsTrue(fbArvore == 2);
			balanceamento(arvore, arvore->raiz);
			fbArvore = fb(arvore->raiz);
			Assert::IsTrue(fbArvore == 0);
		}		
	};
}