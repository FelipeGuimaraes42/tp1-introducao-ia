#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int verticeNumber;
    list<int> *adj;

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v1, int v2);
};
