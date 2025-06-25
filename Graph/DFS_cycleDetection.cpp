#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1000];
bool vis[1000];
bool dfs(int node,int par)
{
    vis[node]=true;
    bool isLoopExist=false;
    for(auto child: graph[node])
    {
        if (vis[child] && child==par)
        {
            continue;
        }
        if(vis[child] && child!=par)
        {
            return true;
        }else
        {
            isLoopExist = dfs(child,node);
        }
    }
        return isLoopExist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bool Loop=false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }else if (dfs(i,0))
        {
            Loop=true;
            break;
        }
    }
    if (Loop)
    {
        cout<<"Loop exist"<<endl;
    }else
    {
        cout<<"Loop dosent exist"<<endl;
    }
    
    

}

