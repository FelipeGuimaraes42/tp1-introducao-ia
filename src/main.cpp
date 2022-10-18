#include <iostream>
#include <string>
#include <vector>
#include "include/InputFile.hpp"
#include "include/Graph.hpp"
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

    Graph graph;

    if (option.compare("BFS") == 0)
    {
        BFS bfs(map);
        bfs.getBFS(positions, numLines, numColumns);
    }
    else if (option.compare("IDS") == 0)
    {
        IDS ids(map);
        graph = ids.getIDS(positions, numLines, numColumns);
    }
    else if (option.compare("UCS") == 0)
    {
        UCS ucs(map);
        graph = ucs.getUCS(positions, numLines, numColumns);
    }
    else if (option.compare("Greedy") == 0)
    {
        Greedy greedy(map);
        graph = greedy.getGreedy(positions, numLines, numColumns);
    }
    else if (option.compare("Astar") == 0)
    {
        AStar aStar(map);
        graph = aStar.getAStar(positions, numLines, numColumns);
    }
    else
    {
        cout << "Invalid Algorithm Option!" << endl;
        cout << "Try again with a valid option." << endl;
        exit(1);
    }

    // graph.printGraph();
    // graph.printGraphV2(5);

    return 0;
}