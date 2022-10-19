#ifndef NODE_CPP
#define NODE_CPP

#include <vector>

using namespace std;

class Node
{
private:
    int vertex;
    float weight;
    pair<int, int> points;
    Node *previous;
    Node *next;

public:
    Node();
    Node(const int vertex, const float weight, const pair<int, int> points, Node *previous);
    ~Node();
    void setNextNode(Node *next);
    Node *getNextNode();
    Node *getPreviousNode();
    int getVertex();
    pair<int, int> getPoints();
    float getWeight();
};

#endif