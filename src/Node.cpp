#include "include/Node.hpp"

Node::Node(const int vertex, const float weight, const pair<int, int> points, Node *previous)
{
    this->vertex = vertex;
    this->weight = weight;
    this->points = points;
    this->previous = previous;
    // this->next = nullptr;
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

int Node::getVertex(){
    return this->vertex;
}