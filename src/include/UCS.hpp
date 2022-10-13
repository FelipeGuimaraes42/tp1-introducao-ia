#include <vector>
#include <string>
#include <list>
#include "Graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

class UCS
{
private:
    vector<vector<float>> map;
    void addToPriorityQueue(list<pair<int, int>> &list, vector<vector<float>> weights, pair<int, int> point);

public:
    UCS(const vector<vector<float>> map);
    ~UCS();
    Graph getUCS(vector<string> initialPosition, int numLines, int numColumns);
};