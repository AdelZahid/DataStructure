#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int n, startCity, minCost = INF;
vector<vector<int>> costMatrix;
vector<int> bestPath;
vector<bool> visited;


int reduceMatrix(vector<vector<int>>& matrix) {
    int reductionCost = 0;


    for (int i = 1; i <= n; i++) {
        int minRowCost = INF;
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] < minRowCost) {
                minRowCost = matrix[i][j];
            }
        }
        if (minRowCost != 0 && minRowCost != INF) {
            reductionCost += minRowCost;
            for (int j = 1; j <= n; j++) {
                if (matrix[i][j] != INF) {
                    matrix[i][j] -= minRowCost;
                }
            }
        }
    }


    for (int j = 1; j <= n; j++) {
        int minColCost = INF;
        for (int i = 1; i <= n; i++) {
            if (matrix[i][j] < minColCost) {
                minColCost = matrix[i][j];
            }
        }
        if (minColCost != 0 && minColCost != INF) {
            reductionCost += minColCost;
            for (int i = 1; i <= n; i++) {
                if (matrix[i][j] != INF) {
                    matrix[i][j] -= minColCost;
                }
            }
        }
    }

    return reductionCost;
}


void tspBranchAndBound(vector<vector<int>>& matrix, int currentCity, int currentCost, int visitedCount, vector<int>& path) {
    if (visitedCount == n) {
        if (matrix[currentCity][startCity] != INF) {
            int totalCost = currentCost + matrix[currentCity][startCity];
            if (totalCost < minCost) {
                minCost = totalCost;
                bestPath = path;
                bestPath.push_back(startCity);
            }
        }
        return;
    }

    for (int nextCity = 1; nextCity <= n; nextCity++) {
        if (!visited[nextCity] && matrix[currentCity][nextCity] != INF) {
            visited[nextCity] = true;
            path.push_back(nextCity);

            vector<vector<int>> reducedMatrix = matrix;
            int reductionCost = reduceMatrix(reducedMatrix);
            int nextCost = currentCost + matrix[currentCity][nextCity] + reductionCost;

            tspBranchAndBound(reducedMatrix, nextCity, nextCost , visitedCount + 1, path);

            visited[nextCity] = false;
            path.pop_back();
        }
    }
}


void solveTSP() {
    visited.assign(n + 1, false);
    vector<int> path = {startCity};
    visited[startCity] = true;

    int initialReductionCost = reduceMatrix(costMatrix);

    tspBranchAndBound(costMatrix, startCity, initialReductionCost, 1, path);

    cout << "Minimum cost: " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;
}

int main() {
    cout << "Input number of cities: ";
    cin >> n;
    costMatrix.assign(n + 1, vector<int>(n + 1));
    cout << "Input matrix that shows costs among cities (999 for infinity): " << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> costMatrix[i][j];
            if (costMatrix[i][j] == 999) {
                costMatrix[i][j] = INF;
            }
        }
    }

    cout << "Enter the starting city (between 1 to " << n << "): ";
    cin >> startCity;

    if (startCity < 1 || startCity > n) {
        cerr << "Invalid starting city!" << endl;
        return 1;
    }

    solveTSP();

    return 0;
}
