#include "include/UCS.hpp"

UCS::UCS(const vector<vector<float>> map)
{
    this->map = map;
}

UCS::~UCS() {}

void UCS::addToPriorityQueue(list<pair<int, int>> &frontier, vector<vector<float>> weights, pair<int, int> point)
{
    bool isPushBack = true;
    if (!frontier.empty())
    {
        for (list<pair<int, int>>::iterator it = frontier.begin(); it != frontier.end(); ++it)
        {
            if (weights[point.first][point.second] <= weights[it->first][it->second])
            {
                frontier.insert(it, point);
                isPushBack = false;
                break;
            }
        }
    }
    if (isPushBack)
    {
        frontier.push_back(point);
    }
}

Graph UCS::getUCS(vector<string> initialPosition, int numLines, int numColumns)
{
    Graph solution(numLines * numColumns);
    pair<int, int> actualVertice = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalVertice = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

    if (this->map[finalVertice.first][finalVertice.second] >= INF)
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
    weights[actualVertice.first][actualVertice.second] = 0;

    list<pair<int, int>> frontier;
    pair<int, int> adjVertice;

    while (true)
    {
        if (finalVertice.first == actualVertice.first && finalVertice.second == actualVertice.second)
        {
            break;
        }
        isVisited[actualVertice.first][actualVertice.second] = true;

        float acumulatedDistance = weights[actualVertice.first][actualVertice.second];

        if ((actualVertice.first > 0) && (actualVertice.first < numLines - 1))
        {
            adjVertice = {actualVertice.first - 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }

            adjVertice = {actualVertice.first + 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }
        }
        if (actualVertice.first == 0)
        {
            adjVertice = {actualVertice.first + 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }
        }
        if (actualVertice.first == numLines - 1)
        {
            adjVertice = {actualVertice.first - 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }
        }

        if ((actualVertice.second > 0) && (actualVertice.second < numColumns - 1))
        {
            adjVertice = {actualVertice.first, actualVertice.second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }

            adjVertice = {actualVertice.first, actualVertice.second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }
        }
        if (actualVertice.second == 0)
        {
            adjVertice = {actualVertice.first, actualVertice.second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }
        }
        if (actualVertice.second == numColumns - 1)
        {
            adjVertice = {actualVertice.first, actualVertice.second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                float aux = this->map[adjVertice.first][adjVertice.second] + acumulatedDistance;
                if (weights[adjVertice.first][adjVertice.second] > aux)
                {
                    weights[adjVertice.first][adjVertice.second] = aux;
                    addToPriorityQueue(frontier, weights, {adjVertice.first, adjVertice.second});
                }
            }
        }

        if (frontier.empty())
        {
            cout << "Cannot leave the vertice" << endl;
            exit(0);
        }

        actualVertice = frontier.front();
        frontier.pop_front();
    }

    cout << weights[actualVertice.first][actualVertice.second] << endl;

    return solution;
}

// cout << "Node: " << actualVertice.first << "," << actualVertice.second << endl;

// for (int i = 0; i < numLines; i++)
// {
//     for (int j = 0; j < numColumns; j++)
//     {
//         cout << weights[i][j] << "\t";
//     }
//     cout << "\n";
// }

// for (int i = 0; i < numLines; i++)
// {
//     for (int j = 0; j < numColumns; j++)
//     {
//         cout << isVisited[i][j] << "\t";
//     }
//     cout << "\n";
// }

// cout << "List: ";
//     for (list<pair<int, int>>::iterator it = frontier.begin(); it != frontier.end(); it++)
//     {
//         cout << it->first << "," << it->second << "-" << weights[it->first][it->second] << "  ";
//     }
//     cout << endl;