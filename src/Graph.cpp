#include "include/Graph.hpp"

using namespace std;

Graph::Graph(int verticesNumber)
{
	this->verticesNumber = verticesNumber;
	adj = new list<int>[verticesNumber];
}

Graph::Graph() {}

Graph::~Graph() {}

int Graph::getVerticesNumber()
{
	return this->verticesNumber;
}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
}