#include "include/BFS.hpp"

BFS::BFS(const vector<vector<float>> map)
{
    this->map = map;
}

BFS::~BFS() {}

void BFS::getBFS(vector<string> initialPosition, int numLines, int numColumns)
{
    pair<int, int> initialPoints = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalPoints = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

    if (this->map[finalPoints.first][finalPoints.second] > 6.0 || this->map[initialPoints.first][initialPoints.second] > 6.0)
    {
        cout << "Unreachable. Try another vertice." << endl;
        exit(0);
    }

    bool isVisited[numLines][numColumns];
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

    isVisited[initialPoints.first][initialPoints.second] = true;

    vector<pair<int, int>> headPoints;
    headPoints.push_back({-1, -1});
    Node actualNode(this->map[initialPoints.first][initialPoints.second], initialPoints, headPoints, 0);

    queue<Node> frontier;
    pair<int, int> adjVertice;

    while (true)
    {
        vector<pair<int, int>> previous = actualNode.getPreviousPoints();
        previous.push_back(actualNode.getPoints());
        actualNode.setPreviousPoints(previous);

        if (finalPoints.first == actualNode.getPoints().first && finalPoints.second == actualNode.getPoints().second)
        {
            break;
        }

        if ((actualNode.getPoints().first > 0) && (actualNode.getPoints().first < numLines - 1))
        {
            adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                isVisited[adjVertice.first][adjVertice.second] = true;
                float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                frontier.push(node);
            }

            adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                isVisited[adjVertice.first][adjVertice.second] = true;
                float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                frontier.push(node);
            }

            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                isVisited[adjVertice.first][adjVertice.second] = true;
                float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);
                frontier.push(node);
            }
        }

        actualNode = frontier.front();
        frontier.pop();
    }

    cout << actualNode.getAccumulatedWeight() << " ";
    for (int i = 1; i < actualNode.getPreviousPoints().size(); i++)
    {
        pair<int, int> aux = actualNode.getPreviousPoints().at(i);
        cout << "(" << aux.first << "," << aux.second << ") ";
    }
    cout << endl;
}
