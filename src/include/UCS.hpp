#include <vector>
#include <string>
#include "Graph.hpp"

using namespace std;

class UCS
{
private:
    vector<vector<float>> map;
public:
    UCS(const vector<vector<float>> map);
    ~UCS();
    Graph getUCS(vector<string> initialPosition, int numLines, int numColumns);
};