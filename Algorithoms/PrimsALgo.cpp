#include <bits/stdc++.h>
using namespace std;

map<string, vector<pair<string, int>>> graph;
map<string, string> parent;
map<string, int> WT;
map<string, bool> vist;
map<string, vector<pair<string, int>>> MST;
map<string, bool> vis;
vector<string> current_path;
vector<vector<string>> all_paths;

void MST_prim(string rt) {
    for (const auto &i : graph) {
        WT[i.first] = INT_MAX;
        parent[i.first] = "NIL";
        vist[i.first] = false;
    }

    WT[rt] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> Q;
    Q.push({0, rt});

    while (!Q.empty()) {
        string u = Q.top().second;
        int current_wt = Q.top().first;
        vist[u] = true;
        Q.pop();
        for (const auto &v : graph[u]) {
            string node = v.first;
            int weight = v.second;
            if (!vist[node] && WT[node] > weight) {
                WT[node] = weight;
                parent[node] = u;
                Q.push({WT[node], node});
            }
        }
    }

    cout << "Minimum Spanning Tree: " << endl;
    for (const auto &i : graph) {
        if (parent[i.first] != "NIL") {
            cout << parent[i.first] << " " << i.first << " " << WT[i.first] << endl;
        }
    }
}

// void Make_newgraph() {
//     for (const auto &i : graph) {
//         if (parent[i.first] != "NIL") {
//             MST[parent[i.first]].push_back({i.first, WT[i.first]});
//             MST[i.first].push_back({parent[i.first], WT[i.first]});
//         }
//     }
// }

// void pathtrack(string source, string tar) {
//     vis[source] = true;
//     current_path.push_back(source);
//     if (source == tar) {
//         all_paths.push_back(current_path);
//         current_path.pop_back();
//         return;
//     }
//     for (auto &child : MST[source]) {
//         if (!vis[child.first]) {
//             pathtrack(child.first, tar);
//             vis[child.first] = false;
//         }
//     }
//     current_path.pop_back();
// }

// void find_the_weight(string source, string tar) {
//     all_paths.clear();  
//     pathtrack(source, tar);
//     int min_weight = INT_MAX;

//     map<pair<string, string>, int> edge_weights;
//     for (const auto &i : graph) {
//         for (const auto &v : i.second) {
//             edge_weights[{i.first, v.first}] = v.second;
//             edge_weights[{v.first, i.first}] = v.second;  
//         }
//     }

//     for (auto &path : all_paths) {
//         int weight = 0;
//         for (int i = 0; i < path.size() - 1; i++) {
//             string from = path[i];
//             string to = path[i + 1];
//             weight += edge_weights[{from, to}];
//         }
//         if (weight < min_weight) {
//             min_weight = weight;
//         }
//     }
//     cout << "The minimum weight from " << source << " to " << tar << " is: " << min_weight << endl;
// }

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }


    for(const auto &i: graph)
    {
        vist[i.first] = false;
    }
    
    for(const auto &i: graph)
    {
        if (!vist[i.first])
        {
            MST_prim(i.first);
        }
        
    }
    // cout << "Minimum Spanning Tree: " << endl;
    // for (const auto &i : graph) {
    //     if (parent[i.first] != "NIL") {
    //         cout << parent[i.first] << " " << i.first << " " << WT[i.first] << endl;
    //     }
    // }

    // Make_newgraph();

    // string u, v;
    // cout << "\nEnter the source and destination nodes: ";
    // cin >> u >> v;

    // pathtrack(u, v);

    // cout << "\nPaths from " << u << " to " << v << ":\n";
    // for (auto &path : all_paths) {
    //     for (auto &node : path) {
    //         cout << node << "->";
    //     }
    //     cout << endl;
    // }

    // find_the_weight(u, v);

    return 0;
}
