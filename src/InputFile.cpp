#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InputFile
{
private:
    // Attributes
    string fileName;

    // Private Method
    void printVector(const vector<string> map)
    {
        for (int i = 0; i < map.size(); i++)
        {
            cout << map[i] << endl;
        }
    }

public:
    // Constructor
    InputFile(string fileName)
    {
        this->fileName = fileName;
    }

    // Destructor
    ~InputFile() {}

    // Methods
    vector<string> getFileContent()
    {
        ifstream source;
        source.open(this->fileName);
        vector<string> lines;
        string line;
        while (getline(source, line))
        {
            lines.push_back(line);
        }
        // printVector(lines);
        return lines;
    }
};