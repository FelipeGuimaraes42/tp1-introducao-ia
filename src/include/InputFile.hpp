#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

class InputFile
{
private:
    string fileName;
    void readLines(vector<string> &lines, int &numLines, int &numColumns);
    void printMap(const vector<vector<float>> pesos, int numLines, int numColumns);
    vector<vector<float>> convertSymbolsToWeight(const int numLines, const int numColumns, const vector<string> symbolMap);

public:
    InputFile(string fileName);
    ~InputFile();
    vector<vector<float>> getFileContent(int &linesNumber, int &columnsNumber);
};