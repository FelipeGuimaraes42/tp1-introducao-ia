#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class ReadFile
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
    ReadFile(string fileName)
    {
        this->fileName = fileName;
    }
    
    // Destructor
    ~ReadFile() {}

    // Methods
    vector<string> read()
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
};