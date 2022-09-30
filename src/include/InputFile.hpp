#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InputFile
{
private:
    string fileName;
    void readLines(vector<string> &lines, int &numLines, int &numColumns);
    void printVector(const vector<string> map);
    vector<vector<float>> convertSymbolsToWeight(const int numLines, const int numColumns, const vector<string> symbolMap);

public:
    InputFile(string fileName);
    ~InputFile();
    vector<string> getFileContent();
};