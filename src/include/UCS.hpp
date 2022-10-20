#include <vector>
#include <string>
#include <list>
#include <iostream>
#include "Node.hpp"

using namespace std;

class UCS
{
private:
    vector<vector<float>> map;
    void addToPriorityQueue(list<Node> &list, vector<vector<float>> weights, Node vertex);

public:
    UCS(const vector<vector<float>> map);
    ~UCS();
    void getUCS(vector<string> initialPosition, int numLines, int numColumns);
};