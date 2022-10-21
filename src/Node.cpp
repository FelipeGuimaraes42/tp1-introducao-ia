#include "include/Node.hpp"

Node::Node()
{
    this->weight = 0;
    this->accumulatedWeight = 0;
    this->points = {-1, -1};
}

Node::Node(const float weight, const pair<int, int> points, vector<pair<int, int>> previousPoints, float accumulatedWeight)
{
    this->weight = weight;
    this->accumulatedWeight = accumulatedWeight;
    this->points = points;
    this->previousPoints = previousPoints;
}

Node::~Node() {}

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