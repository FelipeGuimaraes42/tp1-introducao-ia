#include "include/BFS.hpp"

BFS::BFS(const vector<vector<float>> map)
{
    this->map = map;
}

BFS::~BFS() {}

void BFS::printGraph(vector<Node> adj[], int V)
{
    for (int d = 0; d < V; ++d)
    {
        cout << "\n Vertex " << d << ":";
        for (auto x : adj[d])
        {
            cout << "-> " << x.getPoints().first << "," << x.getPoints().second;
        }
        cout << endl;
    }
}

void BFS::getBFS(vector<string> initialPosition, int numLines, int numColumns)
{
    pair<int, int> initialPoints = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalPoints = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

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

    int nodeCounter = 0;
    int parentCounter = 0;

    Node actualNode(nodeCounter, this->map[initialPoints.first][initialPoints.second], initialPoints, nullptr);

    vector<Node> vertexList;
    vertexList.push_back(actualNode);

    queue<Node> frontier;
    pair<int, int> adjVertice;

    while (true)
    {
        cout << actualNode.getPoints().first << "," << actualNode.getPoints().second << "  ";
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
                Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                frontier.push(node);
                vertexList.push_back(node);
            }

            adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                frontier.push(node);
                vertexList.push_back(node);
            }

            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
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
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                frontier.push(node);
                vertexList.push_back(node);
            }
        }

        actualNode = frontier.front();
        parentCounter = actualNode.getVertex();
        frontier.pop();
    }
    cout << endl;

    Node *aux;
    for (int i = vertexList.size() - 1; i >= 0; i--)
    {
        if (vertexList.at(i).getPoints().first == finalPoints.first && vertexList.at(i).getPoints().second == finalPoints.second)
        {
            aux = &vertexList.at(i);
            break;
        }
    }

    while (aux != nullptr)
    {
        cout << aux->getPoints().first << "," << aux->getPoints().second << "\t";
        aux = aux->getPreviousNode();
    }
    cout << endl;
}
