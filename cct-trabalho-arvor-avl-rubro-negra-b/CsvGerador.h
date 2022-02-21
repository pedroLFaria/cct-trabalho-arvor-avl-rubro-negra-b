#include <map>
#include <string>
#include <fstream>
#include <vector>
#include<filesystem>

namespace fs = std::experimental::filesystem;
using namespace std;
class CsvGerador
{
public:
	static void gerarCsv(string nomeArquivo, map<string, vector<string>>);
private:
	static vector<string> getCabecalho(map<string, vector<string>>);
	static vector<string> getLinhas(vector<string>, map<string, vector<string>>);
	static void criarDiretorio();
};