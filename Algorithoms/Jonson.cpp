#include <bits/stdc++.h>
using namespace std;

map<string, int> dis;
map<string, string> par;
map<string, vector<pair<string, int>>> graph;
map<string, vector<pair<string, int>>> new_graph;
map<string, bool> visited;

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

void Make_newgraph() {
    for (const auto& u : graph) {
        for (const auto& v : u.second) {
            int c = dis[u.first] + v.second - dis[v.first];
            new_graph[u.first].push_back({v.first, c});
        }
    }
}

bool BellmanFord(string src) {
    ISS(src);
    int n = graph.size();
    for (int i = 1; i < n; i++) {
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

void DJKSTRA(string src) {
    ISS(src);
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        string u = pq.top().second;
        visited[u] = true;
        pq.pop();
        for (auto& i : new_graph[u]) {
            string v = i.first;
            int c = i.second;
            Relax(u, v, c);
            if (!visited[v]) {
                pq.push({dis[v], v});
            }
        }
    }
    for (const auto &i : new_graph)
    {
        string u = i.first;
        if (u != src) {
            cout << "The shortest path to " << u << " is :" << endl;
            path(src, u);
            cout << "The cost is :" << dis[u] << endl;
        }
    }
    for (const auto& i : new_graph) {
        visited[i.first] = false;
    }
}

void Jonson(string src) {
    for (const auto& u : graph) {
        string v = u.first;
        graph[src].push_back({v, 0});
    }

    if (BellmanFord(src)) {
        graph[src].clear();
        Make_newgraph();
        for (const auto& i : new_graph) {
            string u = i.first;
            DJKSTRA(u);
        }
    }
    graph.clear();
    new_graph.clear();
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
    string dum;
    cout << "Enter the dummy Node: " << endl;
    cin >> dum;
    Jonson(dum);
}
