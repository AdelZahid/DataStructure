#include<bits/stdc++.h>
using namespace std;

struct edge {
    int src;
    int dest;
    int weight;

    public: edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

vector<edge*> graph[1000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge* e = new edge(u, v, w);
        graph[u].push_back(e);  
    }

    for (int i = 0; i < n; i++) {
        if (!graph[i].empty()) {
            cout << i << "->";
            for (int j = 0; j < graph[i].size(); j++) {
                cout << graph[i][j]->dest << "," << graph[i][j]->weight << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
