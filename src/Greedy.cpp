#include "include/Greedy.hpp"

Greedy::Greedy(const vector<vector<float>> map)
{
    this->map = map;
}

Greedy::~Greedy() {}

vector<vector<int>> Greedy::calculateManhattanDistances(const pair<int, int> finalPosition, const int numLines, const int numColumns)
{
    vector<vector<int>> distances;
    for (int x = 0; x < numLines; x++)
    {
        vector<int> aux;
        for (int y = 0; y < numColumns; y++)
        {
            float distance = abs(x - finalPosition.first) + abs(y - finalPosition.second);
            aux.push_back(distance);
            // cout << distance << "\t";
        }
        distances.push_back(aux);
        // cout << endl;
    }

    return distances;
}

vector<vector<double>> Greedy::calculateEuclideanDistance(const pair<int, int> finalPosition, const int numLines, const int numColumns)
{
    vector<vector<double>> distances;
    for (int x = 0; x < numLines; x++)
    {
        vector<double> aux;
        for (int y = 0; y < numColumns; y++)
        {
            double xd = finalPosition.first - x;
            double yd = finalPosition.second - y;
            double distance = sqrt(xd * xd + yd * yd);
            aux.push_back(distance);
            // cout << distance << "\t";
        }
        distances.push_back(aux);
        // cout << endl;
    }

    return distances;
}

void Greedy::addToPriorityQueue(list<Node> &frontier, Node vertex)
{
    bool isPushBack = true;
    if (!frontier.empty())
    {
        for (list<Node>::iterator it = frontier.begin(); it != frontier.end(); ++it)
        {
            if (vertex.getWeight() <= it->getWeight())
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

void Greedy::getGreedy(vector<string> initialPosition, int numLines, int numColumns)
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

    // vector<vector<int>> heuristicValue = this->calculateManhattanDistances(finalVertice, numLines, numColumns);
    const vector<vector<double>> heuristicValue = this->calculateEuclideanDistance(finalPoints, numLines, numColumns);
    double result = 0;

    int nodeCounter = 0;
    int parentCounter = 0;
    Node actualNode(nodeCounter, this->map[initialPoints.first][initialPoints.second], initialPoints, nullptr);

    vector<Node> vertexList;
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

        vector<Node> actualNodeFrontier;
        isVisited[actualNode.getPoints().first][actualNode.getPoints().second] = true;

        if ((actualNode.getPoints().first > 0) && (actualNode.getPoints().first < numLines - 1))
        {
            adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }

            adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }
        }
        if (actualNode.getPoints().first == 0)
        {
            adjVertice = {actualNode.getPoints().first + 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }
        }
        if (actualNode.getPoints().first == numLines - 1)
        {
            adjVertice = {actualNode.getPoints().first - 1, actualNode.getPoints().second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }
        }

        if ((actualNode.getPoints().second > 0) && (actualNode.getPoints().second < numColumns - 1))
        {
            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }

            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }
        }
        if (actualNode.getPoints().second == 0)
        {
            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }
        }
        if (actualNode.getPoints().second == numColumns - 1)
        {
            adjVertice = {actualNode.getPoints().first, actualNode.getPoints().second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + result;
                weights[adjVertice.first][adjVertice.second] = aux;
                Node node(++nodeCounter, heuristicValue[adjVertice.first][adjVertice.second], adjVertice, &(vertexList.at(parentCounter)));
                vertexList.push_back(node);
                addToPriorityQueue(frontier, node);

                actualNodeFrontier.push_back(node);
            }
        }

        if (actualNodeFrontier.empty() && frontier.empty())
        {
            cout << "Cannot leave the vertice" << endl;
            exit(0);
        }

        if (actualNodeFrontier.empty())
        {
            actualNode = frontier.front();
            parentCounter = actualNode.getVertex();
            frontier.pop_front();
            // TODO Verify if this weight is INF
            // TODO remove the node that leads to a dead end from frontier
            result = weights[actualNode.getPoints().first][actualNode.getPoints().second];
            continue;
        }

        actualNode = actualNodeFrontier.front();
        for (int i = 0; i < actualNodeFrontier.size(); i++)
        {
            if (heuristicValue[actualNode.getPoints().first][actualNode.getPoints().second] >
                heuristicValue[actualNodeFrontier.at(i).getPoints().first][actualNodeFrontier.at(i).getPoints().second])
            {
                actualNode = actualNodeFrontier.at(i);
            }
        }
        parentCounter = actualNode.getVertex();
        result += this->map[actualNode.getPoints().first][actualNode.getPoints().second];
    }

    // Node *aux;
    // for (int i = vertexList.size() - 1; i >= 0; i--)
    // {
    //     if (vertexList.at(i).getPoints().first == finalPoints.first && vertexList.at(i).getPoints().second == finalPoints.second)
    //     {
    //         aux = &vertexList.at(i);
    //         break;
    //     }
    // }

    // vector<pair<int, int>> responsePoints;
    // float responseWeight = 0.0;
    // while (aux != nullptr)
    // {
    //     responsePoints.push_back(aux->getPoints());
    //     responseWeight += aux->getWeight();
    //     aux = aux->getPreviousNode();
    // }
    // responseWeight -= this->map[initialPoints.first][initialPoints.second];

    // cout << responseWeight << " ";

    // for (int i = responsePoints.size() - 1; i >= 0; i--)
    // {
    //     cout << "(" << responsePoints.at(i).first << "," << responsePoints.at(i).second << ") ";
    // }
    // cout << endl;

    cout << "Result:" << result << endl;
}
