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

    int nodeCounter;
    int parentCounter;

    vector<Node> vertexList;

    int depth = 0;
    bool foundSolution = false;

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
        nodeCounter = 0;
        parentCounter = 1;

        isVisited[initialPoints.first][initialPoints.second] = true;

        Node actualNode(nodeCounter, this->map[initialPoints.first][initialPoints.second], initialPoints, nullptr);
        vertexList.clear();
        vertexList.push_back(actualNode);
        nodeCounter++;
        vertexList.push_back(actualNode);

        stack<Node> frontier;
        pair<int, int> adjVertice;

        while (true)
        {
            cout << actualNode.getPoints().first << "," << actualNode.getPoints().second << " ";
            if (finalPoints.first == actualNode.getPoints().first && finalPoints.second == actualNode.getPoints().second)
            {
                foundSolution = true;
                break;
            }

            if ((actualNode.getPoints().first > 0) && (actualNode.getPoints().first < numLines - 1))
            {
                adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }

                adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }
            }
            if (actualNode.getPoints().first == 0)
            {
                adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }
            }
            if (actualNode.getPoints().first == numLines - 1)
            {
                adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }
            }

            if ((actualNode.getPoints().second > 0) && (actualNode.getPoints().second < numColumns - 1))
            {
                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }

                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }
            }
            if (actualNode.getPoints().second == 0)
            {
                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }
            }
            if (actualNode.getPoints().second == numColumns - 1)
            {
                adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
                if (!isVisited[adjVertice.first][adjVertice.second] && this->isValidDepth(initialPoints, adjVertice, depth))
                {
                    isVisited[adjVertice.first][adjVertice.second] = true;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    frontier.push(node);
                    vertexList.push_back(node);
                }
            }

            if (frontier.empty())
            {
                break;
            }

            actualNode = frontier.top();
            parentCounter = actualNode.getVertex();
            frontier.pop();
        }
        cout << endl;
    }

    Node *aux;
    for (int i = vertexList.size() - 1; i >= 0; i--)
    {
        if (vertexList.at(i).getPoints().first == finalPoints.first && vertexList.at(i).getPoints().second == finalPoints.second)
        {
            aux = &vertexList.at(i);
            break;
        }
    }

    vector<pair<int, int>> responsePoints;
    float responseWeight = 0.0;
    while (aux != nullptr)
    {
        responsePoints.push_back(aux->getPoints());
        responseWeight += aux->getWeight();
        aux = aux->getPreviousNode();
    }
    responseWeight -= this->map[initialPoints.first][initialPoints.second];

    cout << responseWeight << " ";

    for (int i = responsePoints.size() - 1; i >= 0; i--)
    {
        cout << "(" << responsePoints.at(i).first << "," << responsePoints.at(i).second << ") ";
    }
    cout << endl;
}