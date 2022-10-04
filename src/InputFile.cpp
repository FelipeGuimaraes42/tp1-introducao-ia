#include "include/InputFile.hpp"

void InputFile::printVector(const vector<string> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        cout << map[i] << endl;
    }
}

vector<vector<float>> InputFile::convertSymbolsToWeight(const int numLines, const int numColumns, const vector<string> symbolMap)
{
    vector<vector<float>> pesos;
    for (int i = 0; i < numLines; i++)
    {
        vector<float> line;
        for (int j = 0; j < numColumns; j++)
        {
            switch (symbolMap.at(i).at(j))
            {
            case 43:
                line.push_back(2.5);
                break;
            case 46:
                line.push_back(1.0);
                break;
            case 120:
                line.push_back(6.0);
                break;
            case 59:
                line.push_back(1.5);
                break;

            default:
                line.push_back(INF);
                break;
            }
        }
        pesos.push_back(line);
    }
    for (int i = 0; i < numLines; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            cout << pesos.at(i).at(j) << "\t";
        }
        cout << endl;
    }
    return pesos;
}

void InputFile::readLines(vector<string> &lines, int &numLines, int &numColumns)
{
    ifstream file;
    file.open(this->fileName);
    string line;
    string stringColumns;
    file >> stringColumns;
    string stringLines;
    file >> stringLines;

    while (getline(file, line))
    {
        lines.push_back(line);
    }
    lines.erase(lines.begin());

    numLines = stoi(stringLines);
    numColumns = stoi(stringColumns);

    // printVector(lines);
}

InputFile::InputFile(string fileName)
{
    this->fileName = fileName;
}

InputFile::~InputFile() {}

vector<string> InputFile::getFileContent()
{
    vector<string> lines;
    int numLines, numColumns;

    readLines(lines, numLines, numColumns);

    vector<vector<float>> pesos = convertSymbolsToWeight(numLines, numColumns, lines);

    return lines;
}