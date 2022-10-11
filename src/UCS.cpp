#include "include/UCS.hpp"

UCS::UCS(const vector<vector<float>> map)
{
    this->map = map;
}

UCS::~UCS() {}

void UCS::addToPriorityQueue(list<pair<int, int>> &frontier, vector<vector<float>> weights, pair<int, int> point)
{
    if (frontier.size() == 0)
    {
        frontier.push_back(point);
    }
    else
    {
        for (list<pair<int, int>>::iterator it = frontier.begin(); it != frontier.end(); it++)
        {
            if (weights[it->first][it->second] >= weights[point.first][point.second])
            {
                frontier.insert(it, point);
                break;
            }
        }
    }
}

Graph UCS::getUCS(vector<string> initialPosition, int numLines, int numColumns)
{
    Graph solution(numLines * numColumns);
    pair<int, int> actualVertice = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalVertice = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

    bool isVisited[numLines][numColumns];
    vector<vector<float>> weights;

    for (int i = 0; i < numLines; i++)
    {
        vector<float> aux;
        for (int j = 0; j < numColumns; j++)
        {
            isVisited[i][j] = false;
            aux.push_back(INF);
        }
        weights.push_back(aux);
    }
    weights[actualVertice.first][actualVertice.second] = 0;
    isVisited[actualVertice.first][actualVertice.second] = true;

    list<pair<int, int>> frontier;
    bool isBreak = true;

    while (true)
    {
        if (finalVertice.first == actualVertice.first && finalVertice.second == actualVertice.second)
        {
            break;
        }

        float acumulatedDistance = weights[actualVertice.first][actualVertice.second];

        if ((actualVertice.first > 0) && (actualVertice.first < numLines - 1))
        {
            if (!isVisited[actualVertice.first - 1][actualVertice.second])
            {
                float aux = this->map[actualVertice.first - 1][actualVertice.second] + acumulatedDistance;
                if (weights[actualVertice.first - 1][actualVertice.second] > aux)
                    weights[actualVertice.first - 1][actualVertice.second] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first - 1, actualVertice.second});
            }

            if (!isVisited[actualVertice.first + 1][actualVertice.second])
            {
                float aux = this->map[actualVertice.first + 1][actualVertice.second] + acumulatedDistance;
                if (weights[actualVertice.first + 1][actualVertice.second] > aux)
                    weights[actualVertice.first + 1][actualVertice.second] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first + 1, actualVertice.second});
            }
        }
        if (actualVertice.first == 0)
        {
            if (!isVisited[actualVertice.first + 1][actualVertice.second])
            {
                float aux = this->map[actualVertice.first + 1][actualVertice.second] + acumulatedDistance;
                if (weights[actualVertice.first + 1][actualVertice.second] > aux)
                    weights[actualVertice.first + 1][actualVertice.second] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first + 1, actualVertice.second});
            }
        }
        if (actualVertice.first == numLines - 1)
        {
            if (!isVisited[actualVertice.first - 1][actualVertice.second])
            {
                float aux = this->map[actualVertice.first - 1][actualVertice.second] + acumulatedDistance;
                if (weights[actualVertice.first - 1][actualVertice.second] > aux)
                    weights[actualVertice.first - 1][actualVertice.second] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first - 1, actualVertice.second});
            }
        }

        if ((actualVertice.second > 0) && (actualVertice.second < numColumns - 1))
        {
            if (!isVisited[actualVertice.first][actualVertice.second - 1])
            {
                float aux = this->map[actualVertice.first][actualVertice.second - 1] + acumulatedDistance;
                if (weights[actualVertice.first][actualVertice.second - 1] > aux)
                    weights[actualVertice.first][actualVertice.second - 1] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first, actualVertice.second - 1});
            }
            if (!isVisited[actualVertice.first][actualVertice.second + 1])
            {
                float aux = this->map[actualVertice.first][actualVertice.second + 1] + acumulatedDistance;
                if (weights[actualVertice.first][actualVertice.second + 1] > aux)
                    weights[actualVertice.first][actualVertice.second + 1] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first, actualVertice.second + 1});
            }
        }
        if (actualVertice.second == 0)
        {
            if (!isVisited[actualVertice.first][actualVertice.second + 1])
            {
                float aux = this->map[actualVertice.first][actualVertice.second + 1] + acumulatedDistance;
                if (weights[actualVertice.first][actualVertice.second + 1] > aux)
                    weights[actualVertice.first][actualVertice.second + 1] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first, actualVertice.second + 1});
            }
        }
        if (actualVertice.second == numColumns - 1)
        {
            if (!isVisited[actualVertice.first][actualVertice.second - 1])
            {
                float aux = this->map[actualVertice.first][actualVertice.second - 1] + acumulatedDistance;
                if (weights[actualVertice.first][actualVertice.second - 1] > aux)
                    weights[actualVertice.first][actualVertice.second - 1] = aux;
                addToPriorityQueue(frontier, weights, {actualVertice.first, actualVertice.second - 1});
            }
        }

        actualVertice = frontier.front();
        frontier.pop_front();

        isVisited[actualVertice.first][actualVertice.second] = true;
    }

    // for (int i = 0; i < numLines; i++)
    // {
    //     for (int j = 0; j < numColumns; j++)
    //     {
    //         cout << weights[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    return solution;
}

// for (list<pair<int, int>>::iterator it = frontier.begin(); it != frontier.end(); it++)
// {
//     cout << weights[it->first][it->second] << "\t";
// }