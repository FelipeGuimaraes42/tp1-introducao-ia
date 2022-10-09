#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;

class Greedy
{
private:
    vector<vector<float>> map;
public:
    Greedy(vector<vector<float>> map);
    ~Greedy();
    Graph getGreedy(vector<string> initialPosition, int numLines, int numColumns);
};
