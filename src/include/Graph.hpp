#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int verticesNumber;
    list<int> *adj;

public:
    Graph();
    Graph(int verticesNumber);
    ~Graph();
    int getVerticesNumber();
    void addEdge(int v1, int v2);
};

#endif