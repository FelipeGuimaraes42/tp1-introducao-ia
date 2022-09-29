#include "include/InputFile.hpp"

void InputFile::printVector(const vector<string> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        cout << map[i] << endl;
    }
}

InputFile::InputFile(string fileName)
{
    this->fileName = fileName;
}

InputFile::~InputFile() {}

vector<string> InputFile::getFileContent()
{
    ifstream source;
    source.open(this->fileName);
    vector<string> lines;
    string line;
    while (getline(source, line))
    {
        lines.push_back(line);
    }
    printVector(lines);
    return lines;
}