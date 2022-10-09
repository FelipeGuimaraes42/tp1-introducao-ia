#include "include/IDS.hpp"

IDS::IDS(const vector<vector<float>> map)
{
    this->map = map;
}

IDS::~IDS() {}

Graph IDS::getIDS(vector<string> initialPosition, int numLines, int numColumns)
{
    Graph solution(numLines * numColumns);

    pair<int, int> actualVertice = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalVertice = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};

    bool isVisited[numLines][numColumns] = {false};

    stack<pair<int, int>> frontier;
    stack<pair<int, int>> nextFrontier;
    nextFrontier.push(actualVertice);

    while (true)
    {
        if (finalVertice.first == actualVertice.first && finalVertice.second == actualVertice.second)
        {
            break;
        }

        isVisited[actualVertice.first][actualVertice.second] = true;

        if (frontier.empty())
        {
            while (!nextFrontier.empty())
            {
                actualVertice = nextFrontier.top();
                if ((actualVertice.first > 0) && (actualVertice.first < numLines - 1))
                {
                    if (!isVisited[actualVertice.first - 1][actualVertice.second])
                        frontier.push({actualVertice.first - 1, actualVertice.second});

                    if (!isVisited[actualVertice.first + 1][actualVertice.second])
                        frontier.push({actualVertice.first + 1, actualVertice.second});
                }
                if (actualVertice.first == 0)
                {
                    if (!isVisited[actualVertice.first + 1][actualVertice.second])
                        frontier.push({actualVertice.first + 1, actualVertice.second});
                }
                if (actualVertice.first == numLines - 1)
                {
                    if (!isVisited[actualVertice.first - 1][actualVertice.second])
                        frontier.push({actualVertice.first - 1, actualVertice.second});
                }
                if ((actualVertice.second > 0) && (actualVertice.second < numColumns - 1))
                {
                    if (!isVisited[actualVertice.first][actualVertice.second - 1])
                        frontier.push({actualVertice.first, actualVertice.second - 1});
                    if (!isVisited[actualVertice.first][actualVertice.second + 1])
                        frontier.push({actualVertice.first, actualVertice.second + 1});
                }
                if (actualVertice.second == 0)
                {
                    if (!isVisited[actualVertice.first][actualVertice.second + 1])
                        frontier.push({actualVertice.first, actualVertice.second + 1});
                }
                if (actualVertice.second == numColumns - 1)
                {
                    if (!isVisited[actualVertice.first][actualVertice.second - 1])
                        frontier.push({actualVertice.first, actualVertice.second - 1});
                }
                nextFrontier.pop();
            }
        }

        cout << actualVertice.first << " " << actualVertice.second << endl;

        actualVertice = frontier.top();
        nextFrontier.push(frontier.top());
        frontier.pop();
    }

    cout << actualVertice.first << " " << actualVertice.second << endl;

    return solution;
}