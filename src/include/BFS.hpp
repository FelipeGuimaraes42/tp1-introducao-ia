#include <vector>
#include <queue>
#include <string>
#include "Graph.hpp"

using namespace std;

class BFS
{
private:
    vector<vector<float>> map;
public:
    BFS(const vector<vector<float>> map);
    ~BFS();
    Graph getBFS(vector<string> initialPosition, int numLines, int numColumns);
};