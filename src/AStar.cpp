#include "include/AStar.hpp"

AStar::AStar(const vector<vector<float>> map)
{
    this->map = map;
}

AStar::~AStar() {}

vector<vector<double>> AStar::calculateEuclideanDistance(const pair<int, int> finalPosition, const int numLines, const int numColumns)
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
            distance += this->map[x][y];
            aux.push_back(distance);
            // cout << distance << "\t";
        }
        distances.push_back(aux);
        // cout << endl;
    }

    return distances;
}

void AStar::getAStar(vector<string> initialPosition, int numLines, int numColumns)
{
    pair<int, int> initialVertice = {stoi(initialPosition.at(0)), stoi(initialPosition.at(1))};
    pair<int, int> finalVertice = {stoi(initialPosition.at(2)), stoi(initialPosition.at(3))};
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

    if (this->map[finalVertice.first][finalVertice.second] > 6.0)
    {
        cout << "Unreachable. Try another vertice." << endl;
        exit(0);
    }

    vector<vector<double>> heuristicValue = this->calculateEuclideanDistance(finalVertice, numLines, numColumns);
    double result = 0;

    pair<int, int> actualVertice = initialVertice;

    int retries = 0;

    while (true)
    {
        vector<pair<int, int>> frontier;
        pair<int, int> adjVertice;
        if (retries == 3)
        {
            cout << "Cannot leave the vertice" << endl;
            exit(0);
        }

        if (finalVertice.first == actualVertice.first && finalVertice.second == actualVertice.second)
        {
            break;
        }

        isVisited[actualVertice.first][actualVertice.second] = true;
        // cout << "Node: " << actualVertice.first << "," << actualVertice.second << endl;

        float acumulatedDistance = heuristicValue[actualVertice.first][actualVertice.second];

        if ((actualVertice.first > 0) && (actualVertice.first < numLines - 1))
        {
            adjVertice = {actualVertice.first - 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }

            adjVertice = {actualVertice.first + 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }
        }
        if (actualVertice.first == 0)
        {
            adjVertice = {actualVertice.first + 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }
        }
        if (actualVertice.first == numLines - 1)
        {
            adjVertice = {actualVertice.first - 1, actualVertice.second};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }
        }

        if ((actualVertice.second > 0) && (actualVertice.second < numColumns - 1))
        {
            adjVertice = {actualVertice.first, actualVertice.second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }

            adjVertice = {actualVertice.first, actualVertice.second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }
        }
        if (actualVertice.second == 0)
        {
            adjVertice = {actualVertice.first, actualVertice.second + 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }
        }
        if (actualVertice.second == numColumns - 1)
        {
            adjVertice = {actualVertice.first, actualVertice.second - 1};
            if (!isVisited[adjVertice.first][adjVertice.second])
            {
                frontier.push_back(adjVertice);
            }
        }

        if (frontier.empty())
        {
            actualVertice = initialVertice;
            result = 0;
            retries++;
            continue;
        }

        actualVertice = frontier.front();
        for (int i = 0; i < frontier.size(); i++)
        {
            if (heuristicValue[actualVertice.first][actualVertice.second] > heuristicValue[frontier.at(i).first][frontier.at(i).second])
            {
                actualVertice = frontier.at(i);
            }
        }
        result += this->map[actualVertice.first][actualVertice.second];
    }

    cout << "Result:" << result << endl;
}
