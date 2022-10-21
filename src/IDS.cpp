#include "include/IDS.hpp"

IDS::IDS(const vector<vector<float>> map)
{
    this->map = map;
}

IDS::~IDS() {}

bool IDS::isValidDepth(pair<int, int> initialPoints, pair<int, int> nextPoint, int actualMaxDepths)
{
    // We will use "depth" as column number, but as the graph is a grid, I think it doesn't matter
    if (abs(initialPoints.second - nextPoint.second) > actualMaxDepths)
    {
        return false;
    }
    return true;
}

void IDS::getIDS(vector<string> initialPosition, int numLines, int numColumns)
{
    pair<int, int> initialPoints = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalPoints = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

    if (this->map[finalPoints.first][finalPoints.second] > 6.0 || this->map[initialPoints.first][initialPoints.second] > 6.0)
    {
        cout << "Unreachable. Try another vertice." << endl;
        exit(0);
    }

    bool isVisited[numLines][numColumns];

    int depth = 0;
    bool foundSolution = false;
    Node finalNode;

    while (!foundSolution)
    {
        depth++;

        for (int i = 0; i < numLines; i++)
        {
            for (int j = 0; j < numColumns; j++)
            {
                if (this->map[i][j] > 6.0)
                {
                    isVisited[i][j] = true;
                }
                else
                {
                    isVisited[i][j] = false;
                }
            }
        }

        vector<pair<int, int>> headPoints;
        headPoints.push_back({-1, -1});
        Node actualNode(this->map[initialPoints.first][initialPoints.second], initialPoints, headPoints, 0);

        isVisited[initialPoints.first][initialPoints.second] = true;

        stack<Node> frontier;
        pair<int, int> adjVertice;

        while (true)
        {
            vector<pair<int, int>> previous = actualNode.getPreviousPoints();
            previous.push_back(actualNode.getPoints());
            actualNode.setPreviousPoints(previous);

            if (finalPoints.first == actualNode.getPoints().first && finalPoints.second == actualNode.getPoints().second)
            {
                finalNode = actualNode;
                foundSolution = true;
                break;
            }

            if ((actualNode.getPoints().first > 0) && (actualNode.getPoints().first < numLines - 1))
            {
                adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }

                adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }
            }
            if (actualNode.getPoints().first == 0)
            {
                adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }
            }
            if (actualNode.getPoints().first == numLines - 1)
            {
                adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }
            }

            if ((actualNode.getPoints().second > 0) && (actualNode.getPoints().second < numColumns - 1))
            {
                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }

                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }
            }
            if (actualNode.getPoints().second == 0)
            {
                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }
            }
            if (actualNode.getPoints().second == numColumns - 1)
            {
                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                    frontier.push(node);
                }
            }

            if (frontier.empty())
            {
                break;
            }

            actualNode = frontier.top();
            frontier.pop();
        }
    }

    cout << finalNode.getAccumulatedWeight() << " ";
    for (int i = 1; i < finalNode.getPreviousPoints().size(); i++)
    {
        pair<int, int> aux = finalNode.getPreviousPoints().at(i);
        cout << "(" << aux.first << "," << aux.second << ") ";
    }
    cout << endl;
}