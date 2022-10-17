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
    Node(const int vertex, const float weight, const pair<int, int> points, Node *previous);
    ~Node();
    void setNextNode(Node *next);
    Node *getNextNode();
    int getVertex();
};

#endif