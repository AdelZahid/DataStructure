#include <bits/stdc++.h>
using namespace std;

map<string, int> dis;
map<string, string> par;
map<string, vector<pair<string, int>>> graph;

void ISS(string src) {
    for (const auto& i : graph) {
        dis[i.first] = INT_MAX;
        par[i.first] = "nil";
    }
    dis[src] = 0;
}

void Relax(string u, string v, int c) {
    if (dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        par[v] = u;
    }
}

bool BellmanFord(string src) {
    ISS(src);
    int n = graph.size();

    for (int i = 0; i < n - 1; i++) {
        for (const auto& u : graph) {
            for (const auto& v : u.second) {
                Relax(u.first, v.first, v.second);
            }
        }
    }

    for (const auto& u : graph) {
        for (const auto& v : u.second) {
            if (dis[v.first] > dis[u.first] + v.second) {
                return false; 
            }
        }
    }
    return true;
}

void printPath(string src, string des) {
    if (par[des] == "nil") {
        cout << "No path exists from " << src << " to " << des << endl;
        return;
    }

    vector<string> path;
    for (string v = des; v != src; v = par[v]) {
        path.push_back(v);
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    for (const auto& node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        graph[u].emplace_back(v, c);
    }

    cout << "Enter the source:" << endl;
    string src;
    cin >> src;

    if (BellmanFord(src))
    {
        for (const auto& node : graph) {
            string u = node.first;
            if (u != src) {
                if (dis[u] != INT_MAX) {
                    cout << "The shortest path to " << u << " is:" << endl;
                    printPath(src, u);
                    cout << "The cost is: " << dis[u] << endl;
                } else {
                    cout << "No path to " << u << endl;
                }
            }
        }
    } else {
        cout << "Graph contains a negative-weight cycle!" << endl;
    }

    return 0;
}
