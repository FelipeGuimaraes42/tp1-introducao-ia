#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Node.hpp"

#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int verticesNumber;
    Node **adjLists;

public:
    Graph();
    Graph(int verticesNumber);
    ~Graph();
    int getVerticesNumber();
    void addEdge(const int s, const int d, Node *vertice);
    void printGraph();
};

#endif