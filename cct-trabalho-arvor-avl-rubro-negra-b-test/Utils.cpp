#include "pch.h"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void visitarLogger(int valor) {
	Logger::WriteMessage(std::to_string(valor).c_str());
	Logger::WriteMessage("\n");
}