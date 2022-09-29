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
    void printVector(const vector<string> map);

public:
    // Constructor
    InputFile(string fileName);

    // Destructor
    ~InputFile();

    // Methods
    vector<string> getFileContent();
};