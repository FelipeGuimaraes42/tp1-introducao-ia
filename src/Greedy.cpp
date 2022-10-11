#include "include/Greedy.hpp"

Greedy::Greedy(vector<vector<float>> map)
{
    this->map = map;
}

Greedy::~Greedy() {}

// vector<vector<float>> Greedy::calculateHeuristic(vector<string> initialPosition, int numLines, int numColumns){
//     return NULL;
// }

Graph Greedy::getGreedy(vector<string> initialPosition, int numLines, int numColumns)
{
    Graph solution(numLines * numColumns);

    // vector<vector<float>> heuristicValue = this->calculateHeuristic(initialPosition, numLines, numColumns);

    return solution;
}
