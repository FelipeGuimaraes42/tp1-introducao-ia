#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <cmath>
#include "Node.hpp"

using namespace std;

class Greedy
{
private:
    vector<vector<float>> map;
    vector<vector<int>> calculateManhattanDistances(pair<int, int> finalPosition, int numLines, int numColumns);
    vector<vector<double>> calculateEuclideanDistance(pair<int, int> finalPosition, int numLines, int numColumns);
    void addToPriorityQueue(list<Node> &list, Node &vertex);

public:
    Greedy(vector<vector<float>> map);
    ~Greedy();
    void getGreedy(vector<string> initialPosition, int numLines, int numColumns);
};
