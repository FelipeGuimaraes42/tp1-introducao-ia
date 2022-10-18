#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;

class BFS
{
private:
    vector<vector<float>> map;
public:
    BFS(const vector<vector<float>> map);
    ~BFS();
    void getBFS(vector<string> initialPosition, int numLines, int numColumns);
    void printGraph(vector<Node> adj[], int V);
};