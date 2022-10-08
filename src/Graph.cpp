#include "include/Graph.hpp"

using namespace std;

Graph::Graph(int verticeNumber)
{
	this->verticeNumber = verticeNumber;
	adj = new list<int>[verticeNumber];
}

Graph::~Graph() {}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
}