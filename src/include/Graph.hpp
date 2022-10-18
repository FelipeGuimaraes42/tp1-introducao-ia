#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Node.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int verticesNumber;
    vector<Node *>adjLists;

public:
    Graph();
    Graph(int verticesNumber);
    ~Graph();
    int getVerticesNumber();
    void addEdge(Node *vertice);
    void printGraph();
};

#endif