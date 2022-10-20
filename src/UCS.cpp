#include "include/UCS.hpp"

UCS::UCS(const vector<vector<float>> map)
{
    this->map = map;
}

UCS::~UCS() {}

void UCS::addToPriorityQueue(list<Node> &frontier, vector<vector<float>> weights, Node vertex)
{
    bool isPushBack = true;
    if (!frontier.empty())
    {
        for (list<Node>::iterator it = frontier.begin(); it != frontier.end(); ++it)
        {
            if (weights[vertex.getPoints().first][vertex.getPoints().second] <= weights[it->getPoints().first][it->getPoints().second])
            {
                frontier.insert(it, vertex);
                isPushBack = false;
                break;
            }
        }
    }
    if (isPushBack)
    {
        frontier.push_back(vertex);
    }
}

void UCS::getUCS(vector<string> initialPosition, int numLines, int numColumns)
{
    pair<int, int> initialPoints = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalPoints = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};
    if (this->map[finalPoints.first][finalPoints.second] > 6.0 || this->map[initialPoints.first][initialPoints.second] > 6.0)
    {
        cout << "Unreachable. Try another vertice." << endl;
        exit(0);
    }

    bool isVisited[numLines][numColumns];
    vector<vector<float>> weights;

    for (int i = 0; i < numLines; i++)
    {
        vector<float> aux;
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
            aux.push_back(INF);
        }
        weights.push_back(aux);
    }
    weights[initialPoints.first][initialPoints.second] = 0;

    int nodeCounter = 0;
    int parentCounter = 1;
    Node actualNode(nodeCounter, this->map[initialPoints.first][initialPoints.second], initialPoints, nullptr);

    vector<Node> vertexList;
    vertexList.push_back(actualNode);
    nodeCounter++;
    vertexList.push_back(actualNode);

    list<Node> frontier;
    pair<int, int> adjVertice;
    Node *lastVertex;

    while (true)
    {
        if (finalPoints.first == actualNode.getPoints().first && finalPoints.second == actualNode.getPoints().second)
        {
            break;
            lastVertex = &vertexList.at(actualNode.getVertex());
        }
        isVisited[actualNode.getPoints().first][actualNode.getPoints().second] = true;

        float acumulatedDistance = weights[actualNode.getPoints().first][actualNode.getPoints().second];

        if ((actualNode.getPoints().first > 0) && (actualNode.getPoints().first < numLines - 1))
        {
            adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }

            adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }
        }
        if (actualNode.getPoints().first == 0)
        {
            adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }
        }
        if (actualNode.getPoints().first == numLines - 1)
        {
            adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }
        }

        if ((actualNode.getPoints().second > 0) && (actualNode.getPoints().second < numColumns - 1))
        {
            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }

            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }
        }
        if (actualNode.getPoints().second == 0)
        {
            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }
        }
        if (actualNode.getPoints().second == numColumns - 1)
        {
            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    Node node(++nodeCounter, this->map[adjVertice.first][adjVertice.second], adjVertice, &vertexList.at(parentCounter));
                    vertexList.push_back(node);
                    addToPriorityQueue(frontier, weights, node);
                }
            }
        }

        if (frontier.empty())
        {
            cout << "Cannot leave the vertice" << endl;
            exit(0);
        }

        actualNode = frontier.front();
        parentCounter = actualNode.getVertex();
        frontier.pop_front();
    }

    // cout << weights[actualNode.getPoints().first][actualNode.getPoints().second] << endl;

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

    // vector<pair<int, int>> responsePoints;
    // float responseWeight = 0.0;
    // while (lastVertex != nullptr)
    // {
    //     responsePoints.push_back(lastVertex->getPoints());
    //     responseWeight += lastVertex->getWeight();
    //     lastVertex = lastVertex->getPreviousNode();
    // }
    // responseWeight -= this->map[initialPoints.first][initialPoints.second];

    // cout << responseWeight << " ";

    // for (int i = responsePoints.size() - 1; i >= 0; i--)
    // {
    //     cout << "(" << responsePoints.at(i).first << "," << responsePoints.at(i).second << ") ";
    // }
    // cout << endl;
}