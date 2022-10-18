#include "include/Graph.hpp"

using namespace std;

Graph::Graph(int verticesNumber)
{
	this->verticesNumber = verticesNumber;
	// adjLists = {nullptr};
	// for (int i = 0; i < verticesNumber; i++)
	// {
	// 	this->adjLists[i] = nullptr;
	// }
}

Graph::Graph() {}

Graph::~Graph() {}

int Graph::getVerticesNumber()
{
	return this->verticesNumber;
}

void Graph::addEdge(Node *vertice)
{
	// this->adjLists[vertice->getVertex()] = vertice;
	this->adjLists.push_back(vertice);
}

void Graph::printGraph()
{
	int v;
	// for (v = 0; v < this->verticesNumber; v++)
	for (v = 0; v < this->adjLists.size(); v++)
	{
		Node *temp = this->adjLists[v];
		cout << "\n Vertex " << v<<  "%d\n: ";
		while (temp != nullptr)
		{
			cout << temp->getVertex() <<  "-> ";
			temp = temp->getNextNode();
		}
		printf("\n");
	}
}