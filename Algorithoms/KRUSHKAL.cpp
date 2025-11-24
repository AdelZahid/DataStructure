#include<bits/stdc++.h>
using namespace std;

map<string, vector<pair<string, int>>> graph;
map<string, vector<pair<string, int>>> MST;
map<string, string> parent; 
map<string, int> RP;      
map<pair<string, string>, int> WT;
vector<pair<string, string>> T;
map<string, string> MST_parent;
map<string, bool> vis;
vector<string> current_path;
vector<vector<string>> all_paths;

void make_set() {
    for(auto i : graph) {
        parent[i.first] = i.first; 
        RP[i.first] = 0;
    }
}

string find(string u) {
    if(parent[u] != u) 
    {
        parent[u] = find(parent[u]); 
    }
    return parent[u];
}
void union_sets(string u, string v) {
    string root_u = find(u);
    string root_v = find(v);

    if(root_u != root_v) {
        if(RP[root_u] > RP[root_v]) {
            parent[root_v] = root_u;
        } else if(RP[root_u] < RP[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            RP[root_u]++;
        }
    }
}
void Kruskal() {
    make_set();
    priority_queue<pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> Q;
    
    for(auto i : graph) {
        for(auto j : i.second) {
            Q.push({j.second, {i.first, j.first}});
        }
    }

    while(!Q.empty()) {
        string u = Q.top().second.first;
        string v = Q.top().second.second;
        int w = Q.top().first;
        Q.pop();
        if(find(u) != find(v)) 
        {
            T.push_back({u, v});
            WT[{u, v}] = w;
            MST_parent[v] = u;
            MST_parent[u] = v;
            union_sets(u, v);
        }
    }
}
void Make_another_graph() {
    for(auto i : T) {
        MST[i.first].push_back({i.second, WT[{i.first, i.second}]});
        MST[i.second].push_back({i.first, WT[{i.first, i.second}]});
    }
}
void pathtrack(string source,string tar)
{
    vis[source]=true;
    current_path.push_back(source); 
    if (source==tar)
    {
        all_paths.push_back(current_path);
        current_path.pop_back();
        return;
    }
    for(auto &child: MST[source])
    {
        if (!vis[child.first])
        {
            pathtrack(child.first,tar);
            vis[child.first]=false;
        }
    }
    current_path.pop_back();
}
int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c}); 
    }

    Kruskal();
    cout << endl;
    for(auto i : T) {
        cout << i.first << "->" << i.second <<" " << WT[{i.first, i.second}] << endl;
    }
    cout << endl;
    string u, v;
    cout << "Enter the source and destination nodes: ";
    cin >> u >> v;
    Make_another_graph();
    pathtrack(u, v);
    for(auto &path : all_paths) 
    {
        for(auto &node : path) {
            cout << node << "->";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
