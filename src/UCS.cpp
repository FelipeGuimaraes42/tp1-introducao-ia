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

    vector<pair<int, int>> headPoints;
    headPoints.push_back({-1, -1});
    Node actualNode(this->map[initialPoints.first][initialPoints.second], initialPoints, headPoints, 0);

    list<Node> frontier;
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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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

                    float accumulatedWeight = actualNode.getAccumulatedWeight() + this->map[adjVertice.first][adjVertice.second];
                    Node node(this->map[adjVertice.first][adjVertice.second], adjVertice, actualNode.getPreviousPoints(), accumulatedWeight);

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
        frontier.pop_front();
    }

    cout << actualNode.getAccumulatedWeight() << " ";
    for (int i = 1; i < actualNode.getPreviousPoints().size(); i++)
    {
        pair<int, int> aux = actualNode.getPreviousPoints().at(i);
        cout << "(" << aux.first << "," << aux.second << ") ";
    }
    cout << endl;
}