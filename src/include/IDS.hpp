#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "Node.hpp"

using namespace std;

class IDS
{
private:
    vector<vector<float>> map;
    bool isValidDepth(pair<int, int> initialPoints, pair<int, int> nextPoints, int actualMaxDepth);

public:
    IDS(const vector<vector<float>> map);
    ~IDS();
    void getIDS(vector<string> initialPosition, int numLines, int numColumns);
};