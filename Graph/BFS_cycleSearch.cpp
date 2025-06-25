#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool vis[1000] = {false};

void BFS(int node) 
{
    queue<pair<int, int>> q;    
    q.push({node, -1}); 
    vis[node] = true;
    while (!q.empty()) {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int i = 0; i < graph[u].size(); i++) 
        {
            int x = graph[u][i];
            if (vis[x] && x == parent) 
            {
                continue;
            } 
            else if ( vis[x] && x != parent)
            {
                cout <<"Cycle is found: "<< endl;
                cout<<"Cycle node is: "<<x<<endl;
                return;
            }else
            {
                q.push({x, u});
                vis[x] = true;
            }
            
        }
    }
    cout << "Cycle is not present" << endl;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << "The graph is: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    BFS(1);
    return 0;
}
