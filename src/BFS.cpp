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
    vector<Node> graph[numLines * numColumns];
    pair<int, int> actualVertice = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalVertice = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};
    Node *lastVertex = nullptr;
    int nodeCounter = 0;

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

    isVisited[actualVertice.first][actualVertice.second] = true;

    queue<pair<int, int>> frontier;
    pair<int, int> adjVertice;
    // Node *lastVertex;

    while (true)
    {
        Node node(nodeCounter, this->map[actualVertice.first][actualVertice.second], actualVertice, lastVertex);
        graph[nodeCounter].push_back(node);
        // previousNode = &node;
        lastVertex = &(graph[nodeCounter].at(0));
        // lastVertex = &(graph[nodeCounter].at(0));

        if (finalVertice.first == actualVertice.first && finalVertice.second == actualVertice.second)
        {
            break;
        }

        if ((actualVertice.first > 0) && (actualVertice.first < numLines - 1))
        {
            adjVertice = {actualVertice.first - 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }

            adjVertice = {actualVertice.first + 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }
        }
        if (actualVertice.first == 0)
        {
            adjVertice = {actualVertice.first + 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }
        }
        if (actualVertice.first == numLines - 1)
        {
            adjVertice = {actualVertice.first - 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }
        }

        if ((actualVertice.second > 0) && (actualVertice.second < numColumns - 1))
        {
            adjVertice = {actualVertice.first, actualVertice.second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }

            adjVertice = {actualVertice.first, actualVertice.second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }
        }
        if (actualVertice.second == 0)
        {
            adjVertice = {actualVertice.first, actualVertice.second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }
        }
        if (actualVertice.second == numColumns - 1)
        {
            adjVertice = {actualVertice.first, actualVertice.second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push({adjVertice.first, adjVertice.second});
                isVisited[adjVertice.first][adjVertice.second] = true;
                Node node(nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, lastVertex);
                graph[nodeCounter].push_back(node);
            }
        }

        nodeCounter++;
        actualVertice = frontier.front();
        frontier.pop();
    }

    // printGraph(graph, numLines * numColumns);
    // cout << lastVertex->getPreviousNode()->getPoints().first << "," << lastVertex->getPreviousNode()->getPoints().second << endl;

    // Fix the previous node logic
    Node *aux = lastVertex;
    for (int i = nodeCounter; i >= 0; i--)
    {
        aux = aux->getPreviousNode();
        cout << aux->getPoints().first << "," << aux->getPoints().second << "\t";
    }
    cout << endl;
}
