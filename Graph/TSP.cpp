#include <bits/stdc++.h>
using namespace std;

const int INF =INT_MAX;

vector<int> bestPath;
map<int, int> track;
int minCost = INT_MAX;

// Function to reduce matrix and return the reduction cost
int reduceMatrix(vector<vector<int>>& v, int n)
{
    int reductionCost = 0;

    // Row Reduction
    for (int i = 1; i <= n; i++)
    {
        int minCost = INF;
        for (int j = 1; j <= n; j++)
        {
            if (v[i][j] < minCost)
            {
                minCost = v[i][j];
            }
        }
        if (minCost != 0 && minCost != INF)
        {
            reductionCost += minCost;
            for (int j = 1; j <= n; j++)
            {
                if (v[i][j] != INF)
                {
                    v[i][j] -= minCost;
                }
            }
        }
    }

    // Column Reduction
    for (int j = 1; j <= n; j++)
    {
        int minCost = INF;
        for (int i = 1; i <= n; i++)
        {
            if (v[i][j] < minCost)
            {
                minCost = v[i][j];
            }
        }
        if (minCost != 0 && minCost != INF)
        {
            reductionCost += minCost;
            for (int i = 1; i <= n; i++)
            {
                if (v[i][j] != INF)
                {
                    v[i][j] -= minCost;
                }
            }
        }
    }

    return reductionCost;
}

// Recursive function for Branch and Bound TSP
void tspBranchAndBound(vector<vector<int>>& v, int n, int currentCity, int currentCost, int visitedCount, vector<int>& path)
{
    if (visitedCount == n)
    {
        // Return to the starting city
        if (v[currentCity][path[0]] != INF)
        {
            int totalCost = currentCost + v[currentCity][path[0]];
            if (totalCost < minCost)
            {
                minCost = totalCost;
                bestPath = path;
                bestPath.push_back(path[0]); // Return to starting city
            }
        }
        return;
    }

    for (int nextCity = 1; nextCity <= n; nextCity++)
    {
        if (!track[nextCity] && v[currentCity][nextCity] != INF)
        {
            track[nextCity] = 1;
            path.push_back(nextCity);
            // Create a copy of the matrix for reduction
            vector<vector<int>> reducedMatrix = v;
            int reductionCost = reduceMatrix(reducedMatrix, n);
            tspBranchAndBound(reducedMatrix, n, nextCity, currentCost + v[currentCity][nextCity] + reductionCost, visitedCount + 1, path);
            track[nextCity] = 0;
            path.pop_back();
        }
    }
}

int main()
{
    int n;
    cout << "Input number of cities: ";
    cin >> n;

    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    cout << "Input matrix that shows costs among cities (999 for infinity): " << endl;

    for (int i = 1; i <= n; i++)
    {
        track[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }

    int sc;
    cout << "Enter the starting city (between 1 to " << n << "): ";
    cin >> sc;

    vector<int> path;
    path.push_back(sc);
    track[sc] = 1;

    // Initial reduction of the matrix
    int initialReductionCost = reduceMatrix(v, n);

    tspBranchAndBound(v, n, sc, initialReductionCost, 1, path);

    cout << "Minimum cost: " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath)
    {
        cout << city << " ";
    }

}
