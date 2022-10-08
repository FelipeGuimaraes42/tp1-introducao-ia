#include <iostream>
#include <string>
#include <vector>
#include "include/InputFile.hpp"
#include "include/Graph.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string fileName(argv[1]);
    InputFile inputFile(fileName);

    int numLines, numColumns;
    vector<vector<float>> map = inputFile.getFileContent(numLines, numColumns);

    string option(argv[2]);

    Graph solution(numLines * numColumns);

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
        // cout << positions[i] << " ";
    }
    // cout << endl;

    return 0;
}