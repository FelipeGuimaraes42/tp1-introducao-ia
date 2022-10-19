#include "include/Node.hpp"

Node::Node()
{
    this->vertex = 0;
    this->weight = 0;
    this->points = {-1, -1};
    this->previous = nullptr;
    this->next = nullptr;
}

Node::Node(const int vertex, const float weight, const pair<int, int> points, Node *previous)
{
    this->vertex = vertex;
    this->weight = weight;
    this->points = points;
    this->previous = previous;
    this->next = nullptr;
}

Node::~Node() {}

void Node::setNextNode(Node *next)
{
    this->next = next;
}

Node *Node::getNextNode()
{
    return this->next;
}

Node *Node::getPreviousNode()
{
    return this->previous;
}

int Node::getVertex()
{
    return this->vertex;
}

pair<int, int> Node::getPoints()
{
    return this->points;
}

float Node::getWeight()
{
    return this->weight;
}