#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> D; 
vector<vector<vector<int>>> P;

void FloyeWarshell(int graph[][100], int n) {
    int dist[n][n];
    int Path[n][n];

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != INT_MAX && i != j) {
                Path[i][j] = i+1;
            } else {
                Path[i][j] = INT_MAX;
            }
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        Path[i][j] = Path[k][j]; 
                    }
                }
            }
        }
        
        vector<vector<int>> dist_copy(n, vector<int>(n));
        vector<vector<int>> path_copy(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist_copy[i][j] = dist[i][j];
                path_copy[i][j] = Path[i][j];
            }
        }
        D.push_back(dist_copy);
        P.push_back(path_copy);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INT_MAX) 
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int graph[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX; 
            }
        }
    }
    cout << endl;
    cout << endl;

    FloyeWarshell(graph, n);
    cout << endl;
    cout << endl;
    cout<<"Distance Matrices: "<<endl;
    for(int i = 0; i < D.size(); i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(D[i][j][k] == INT_MAX) 
                    cout << "INF ";
                else
                    cout << D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    cout<<"Path Matrices: "<<endl;
    for(int i = 0; i < P.size(); i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(P[i][j][k] == INT_MAX) 
                    cout << "INF ";
                else
                    cout << P[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
