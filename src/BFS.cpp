#include "include/BFS.hpp"

BFS::BFS(const vector<vector<float>> map)
{
    this->map = map;
}

BFS::~BFS() {}

Graph BFS::getBFS(vector<string> initialPosition, int numLines, int numColumns)
{
    Graph solution(numLines * numColumns);
    pair<int, int> actualVertice = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalVertice = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

    bool isVisited[numLines][numColumns];

    for (int i = 0; i < numLines; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            isVisited[i][j] = 0;
        }
    }

    isVisited[actualVertice.first][actualVertice.second] = 1;

    queue<pair<int, int>> frontier;

    while (true)
    {
        if (finalVertice.first == actualVertice.first && finalVertice.second == actualVertice.second)
        {
            break;
        }

        cout << actualVertice.first << " " << actualVertice.second << endl;

        if ((actualVertice.first > 0) && (actualVertice.first < numLines - 1))
        {
            if (!isVisited[actualVertice.first - 1][actualVertice.second])
            {
                frontier.push({actualVertice.first - 1, actualVertice.second});
                isVisited[actualVertice.first - 1][actualVertice.second] = 1;
            }

            if (!isVisited[actualVertice.first + 1][actualVertice.second])
            {
                frontier.push({actualVertice.first + 1, actualVertice.second});
                isVisited[actualVertice.first + 1][actualVertice.second] = 1;
            }
        }
        if (actualVertice.first == 0)
        {
            if (!isVisited[actualVertice.first + 1][actualVertice.second])
            {
                frontier.push({actualVertice.first + 1, actualVertice.second});
                isVisited[actualVertice.first + 1][actualVertice.second] = 1;
            }
        }
        if (actualVertice.first == numLines - 1)
        {
            if (!isVisited[actualVertice.first - 1][actualVertice.second])
            {
                frontier.push({actualVertice.first - 1, actualVertice.second});
                isVisited[actualVertice.first - 1][actualVertice.second] = 1;
            }
        }

        if ((actualVertice.second > 0) && (actualVertice.second < numColumns - 1))
        {
            if (!isVisited[actualVertice.first][actualVertice.second - 1])
            {
                frontier.push({actualVertice.first, actualVertice.second - 1});
                isVisited[actualVertice.first][actualVertice.second - 1] = 1;
            }
            if (!isVisited[actualVertice.first][actualVertice.second + 1])
            {
                frontier.push({actualVertice.first, actualVertice.second + 1});
                isVisited[actualVertice.first][actualVertice.second + 1] = 1;
            }
        }
        if (actualVertice.second == 0)
        {
            if (!isVisited[actualVertice.first][actualVertice.second + 1])
            {
                frontier.push({actualVertice.first, actualVertice.second + 1});
                isVisited[actualVertice.first][actualVertice.second + 1] = 1;
            }
        }
        if (actualVertice.second == numColumns - 1)
        {
            if (!isVisited[actualVertice.first][actualVertice.second - 1])
            {
                frontier.push({actualVertice.first, actualVertice.second - 1});
                isVisited[actualVertice.first][actualVertice.second - 1] = 1;
            }
        }

        actualVertice = frontier.front();
        frontier.pop();
    }

    cout << actualVertice.first << " " << actualVertice.second << endl;

    return solution;
}