#include<bits/stdc++.h>
using namespace std;

bool vis[1000]={false};
vector<int> V[1000];
vector<int> level(1000, -1);
vector<string> color(1000, "white");
vector<int>bicolor(1000,-1);
vector<int> component;
vector<vector<int>> cc;
vector<int> current_path;
vector<vector<int>> all_paths;
bool isbipartate=true;
queue<int> np;
vector<int> cpath;
/*BFS for shortest path*/

void BFS(int source)
{
    queue<int> Q;
    Q.push(source);
    level[source] = 0;
    bicolor[source] = 0;
    while(!Q.empty()) 
    {
    int u = Q.front();
        Q.pop();
        for(int i = 0; i < V[u].size(); i++)
        {
                int v = V[u][i];
                if(level[v] == -1) 
            {
                level[v] = level[u] + 1;
                bicolor[v]=bicolor[u]^1;
                Q.push(v);
            }
            else
            {
                if(bicolor[u] == bicolor[v])
                {
                    isbipartate=false;
                }
            }
            
        }
    }
}

/*DFS for disconnected components*/

void DFS(int source) 
{
    color[source] = "gray";
    component.push_back(source);
    for(auto& child: V[source]) {
        if (color[child] == "white")
        {
            DFS(child);
        }
    }
    color[source] = "black";
}

/*Traking multiple path to destination using DFS*/

void pathtrack(int source,int tar)
{
    vis[source]=true;
    current_path.push_back(source); 
    if (source==tar)
    {
        all_paths.push_back(current_path);
        current_path.pop_back();
        return;
    }
    for(auto &child: V[source])
    {
        if (!vis[child])
        {
            pathtrack(child,tar);
            vis[child]=false;
        }
    }
    current_path.pop_back();
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int A, B;
        cin >> A >> B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    // Initialize levels for BFS
    for(int i = 1; i <= n; i++)
    {
        level[i] = -1;
    }
    BFS(1);
    int maxLevel = 0;
    for(int i = 1; i <= n; i++) {
        if(level[i] > maxLevel) {
            maxLevel = level[i];
        }
    }
    cout << "The graph is: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < V[i].size(); j++) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The shortest path is: " << maxLevel << endl;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == "white") { 
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
    cout << "The connected components are:" << endl;
    for (auto &comp: cc) {
        for(auto &i: comp) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout<<"Enter the target node"<<endl;
    int T;
    cin>>T;
    pathtrack(1,T);
    cout<<endl;
    for(auto &path : all_paths) 
    {
        for(int node : path) {
            cout << node << " ";
            cpath.push_back(node);
        }
        np.push(cpath.back());
        cpath.pop_back();
        cout << endl;
        if(find(path.begin(), path.end(), 5) != path.end() &&
            find(path.begin(), path.end(), 6) != path.end() &&
            path.size() == level[T]+1)
        {
            cout<<"Shortest path exist including 2 and 3"<<endl;
        }
    }
    cout<<level[T]<<endl;
    if (isbipartate)
    {
        cout<<"The graph is bipartate"<<endl;
    }else
    {
        cout<<"The graph is not bipartate"<<endl;
    }
    
    

    return 0;
}
