#include<bits/stdc++.h>
using namespace std;

map<string,bool> vis;
map<string,bool> marked;
map<string, vector<string>> graph;   

vector<string> current_path;         
vector<vector<string>> all_paths;    
/* This is the function whichc detect all prossible cycle for a perticula
noce taking it as a source ,,, here we take a node as a sourec and the 
main node as a target and detect all possible path from the source to 
target node */
void Deadlocks(string source, string tar)
{
    vis[source]=true;
    current_path.push_back(source); 

    if (source==tar)
    {
        all_paths.push_back(current_path);
        current_path.pop_back();
        vis[source]=false;
        return;
    }

    for(auto &child: graph[source])
    {
        if (!vis[child] && !marked[child])
        {
            Deadlocks(child,tar);
        }
    }

    current_path.pop_back();
    vis[source]=false;   
}

/*Runnig DFS for each node so that detect all cycle that close to this
particular node*/
void DFS(string node)
{
    current_path.clear();
    current_path.push_back(node);

    for (auto &child: graph[node])
    {
        if (!marked[child])
        {
            Deadlocks(child,node);
        }
    }

    marked[node]=true;  
}

int main()
{
    /* here n is the number of node and m is the number of edge for the
    given example in the slide the input will be
    
6 9
P1 P2
P2 P3
P2 P5
P3 P4
P3 P1
P4 P5
P5 P6
P5 P3
P6 P2

    */
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    for (auto &it : graph)
    {
        if (!marked[it.first])
        {
            DFS(it.first);
        }
    }

    for (auto &path : all_paths)
    {
        for (auto &x : path) cout << x << " ";
        cout << endl;
    }
}
