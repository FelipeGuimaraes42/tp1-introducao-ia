#ifndef NODE_CPP
#define NODE_CPP

#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

class Node
{
private:
    int vertex;
    float weight;
    float accumulatedWeight;
    pair<int, int> points;
    Node *previousNode;
    vector<pair<int, int>> previousPoints;

public:
    Node();
    Node(const int vertex, const float weight, const pair<int, int> points, Node *previous);
    Node(const float weight, const pair<int, int> points, vector<pair<int, int>> previousVector, float accumulatedWeight);
    ~Node();

    int getVertex();
    float getWeight();
    float getAccumulatedWeight();
    Node *getPreviousNode();
    pair<int, int> getPoints();
    vector<pair<int, int>> getPreviousPoints();

    void setAccumulatedWeight(float accumulatedWeight);
    void setPreviousPoints(vector<pair<int, int>> previousPoints);
};

#endif