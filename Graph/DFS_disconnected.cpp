#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
vector<int> color(1000, -1);
vector<int>component;
vector<vector<int>>cc;

int DFS(int source) {
    color[source] = 1;
    component.push_back(source);
    for (auto child : graph[source]) 
    {
        if (color[child] == 0)
        {
            DFS(child);
        }
    }
    color[source] = 2;
}

int main() {
    int n, m;
    int mxc = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        color[u] = 0;
        if (v>=0)
        {
            color[v] = 0;
        }
        
        if (u > mxc) {
            mxc = u;
        }else if (v > mxc) {
            mxc = v;
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) { 
            component.clear();
            DFS(i);
            cc.push_back(component);
            count++;
        }
    }
    if (count > 1) {
        cout << "The graph is not connected -> the number of disconnected components is: " << count << endl;
    } else {
        cout << "The graph is connected" << endl;
    }
    cout << "The connected components are: " << endl;
    for (int i = 0; i < cc.size(); i++) {
        for (int j = 0; j < cc[i].size(); j++) {
            cout << cc[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The graph is: " << endl;
    for (int i = 1; i <= mxc; i++) {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j]>=0)
            {
                cout << graph[i][j] << " ";
            }
            
        }
        cout << endl;
    }
    

    return 0;
}