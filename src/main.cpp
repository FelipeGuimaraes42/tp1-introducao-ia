#include <iostream>
#include <string>
#include <vector>
#include "BFS.cpp"
#include "include/InputFile.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string fileName(argv[1]);
    InputFile inputFile(fileName);
    vector<string> map = inputFile.getFileContent();

    string option(argv[2]);

    if (option.compare("BFS") == 0)
    {
        // Call BFS
    }
    else if (option.compare("IDS") == 0)
    {
        // Call BFS
    }
    else if (option.compare("UCS") == 0)
    {
        // Call BFS
    }
    else if (option.compare("Greedy") == 0)
    {
        // Call BFS
    }
    else if (option.compare("Astar") == 0)
    {
        // Call BFS
    }
    else
    {
        cout << "Invalid Algorithm Option!" << endl;
        cout << "Try again with a valid option." << endl;
        exit(1);
    }

    char *positions[4];
    for (int i = 0; i < 4; i++)
    {
        positions[i] = argv[i + 3];
        cout << positions[i] << " ";
    }
    cout << endl;

    return 0;
}