#include <vector>
#include <stack>
#include <string>
#include "Graph.hpp"

using namespace std;

class IDS
{
private:
    vector<vector<float>> map;
public:
    IDS(const vector<vector<float>> map);
    ~IDS();
    Graph getIDS(vector<string> initialPosition, int numLines, int numColumns);
};