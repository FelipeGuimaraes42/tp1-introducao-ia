#include <vector>
#include <iostream>
#include <cmath>
#include <list>
#include "Node.hpp"

class AStar
{
private:
    vector<vector<float>> map;
    vector<vector<double>> calculateEuclideanDistance(pair<int, int> finalPosition, int numLines, int numColumns);
    void addToPriorityQueue(list<Node> &frontier, vector<vector<float>> weights, Node vertex);

public:
    AStar(const vector<vector<float>> map);
    ~AStar();
    void getAStar(vector<string> initialPosition, int numLines, int numColumns);
};