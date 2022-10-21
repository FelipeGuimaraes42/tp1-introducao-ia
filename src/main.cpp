#include <iostream>
#include <string>
#include <vector>
#include "include/InputFile.hpp"
#include "include/BFS.hpp"
#include "include/IDS.hpp"
#include "include/UCS.hpp"
#include "include/Greedy.hpp"
#include "include/AStar.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string fileName(argv[1]);
    InputFile inputFile(fileName);

    int numLines, numColumns;
    vector<vector<float>> map = inputFile.getFileContent(numLines, numColumns);

    string option(argv[2]);

    vector<string> positions;
    for (int i = 0; i < 4; i++)
    {
        positions.push_back(argv[i + 3]);
    }

    if (option.compare("BFS") == 0)
    {
        BFS bfs(map);
        bfs.getBFS(positions, numLines, numColumns);
    }
    else if (option.compare("IDS") == 0)
    {
        IDS ids(map);
        ids.getIDS(positions, numLines, numColumns);
    }
    else if (option.compare("UCS") == 0)
    {
        UCS ucs(map);
        ucs.getUCS(positions, numLines, numColumns);
    }
    else if (option.compare("Greedy") == 0)
    {
        Greedy greedy(map);
        greedy.getGreedy(positions, numLines, numColumns);
    }
    else if (option.compare("Astar") == 0)
    {
        AStar aStar(map);
        aStar.getAStar(positions, numLines, numColumns);
    }
    else
    {
        cout << "Invalid Algorithm Option!" << "\n";
        cout << "Try again with a valid option." << endl;
        exit(0);
    }
    return 0;
}