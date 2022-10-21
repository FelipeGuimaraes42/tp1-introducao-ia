#include "include/Node.hpp"

Node::Node()
{
    this->vertex = 0;
    this->weight = 0;
    this->points = {-1, -1};
    this->previousNode = nullptr;
}

Node::Node(const int vertex, const float weight, const pair<int, int> points, Node *previous)
{
    this->vertex = vertex;
    this->weight = weight;
    this->points = points;
    this->previousNode = previous;
}

Node::Node(const float weight, const pair<int, int> points, vector<pair<int, int>> previousPoints, float accumulatedWeight)
{
    this->weight = weight;
    this->accumulatedWeight = accumulatedWeight;
    this->points = points;
    this->previousPoints = previousPoints;
}

Node::~Node() {}

Node *Node::getPreviousNode()
{
    return this->previousNode;
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

vector<pair<int, int>> Node::getPreviousPoints()
{
    return this->previousPoints;
}

void Node::setPreviousPoints(vector<pair<int, int>> previousPoints)
{
    this->previousPoints = previousPoints;
}

float Node::getAccumulatedWeight()
{
    return this->accumulatedWeight;
}

void Node::setAccumulatedWeight(float accumulatedWeight)
{
    this->accumulatedWeight = accumulatedWeight;
}