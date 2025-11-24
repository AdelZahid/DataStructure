#include <bits/stdc++.h>
using namespace std;

map<string, int> dis;
map<string, string> par;
map<string, vector<pair<string, int>>> graph;
stack<string> Stack;
map<string, bool> visited;

void topologicalSortUtil(string v) {
    visited[v] = true;
    for (auto i : graph[v]) {
        if (!visited[i.first]) {
            topologicalSortUtil(i.first);
        }
    }
    Stack.push(v);
}

void ISS(string src) {
    for (const auto& i : graph) {
        dis[i.first] = INT_MAX;
        par[i.first] = "nil";
    }
    dis[src] = 0;
}

void Relax(string u, string v, int c)
{
    if (dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        par[v] = u;
    }
}

void DAG(string src) {
    visited.clear();
    for (auto i : graph) {
        if (!visited[i.first]) {
            topologicalSortUtil(i.first);
        }
    }
    ISS(src);
    while (!Stack.empty()) {
        string u = Stack.top();
        Stack.pop();
        if(dis[u]!=INT_MAX)
        for (auto i : graph[u]) {
            string v = i.first;
            int c = i.second;
            Relax(u, v, c);
        }
    }
}

void path(string src, string des) {
    if (dis[des] == INT_MAX) {
        cout << "No path" << endl;
        return;
    }
    vector<string> path;
    for (string v = des; v != src; v = par[v]) {
        path.push_back(v);
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    for (const auto& u : path) {
        cout << u << "  ";
    }
    cout << endl;
    path.clear();
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }
    cout << "Enter the source and destination" << endl;
    string src;
    cin >> src;
    DAG(src);
    for (const auto& i : graph) {
        string u = i.first;
        if (u != src) {
            cout << "The shortest path to " << u << " is :" << endl;
            path(src, u);
            cout << "The cost is :" << dis[u] << endl;
        }
    }
}
