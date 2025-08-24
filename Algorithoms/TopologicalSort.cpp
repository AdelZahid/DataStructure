#include<bits/stdc++.h>
using namespace std;
map<string, vector<string>> adj_list;
unordered_map<string, string> color;
struct node
{
    string data;
    node *next;
};
node *root = NULL;
void insert_first(string val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
        return;
    }
}
int length()
{
    node *curr_node = root;
    int count = 0;
    while (curr_node != NULL)
    {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}
void printlist()
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}
void DFS(string source) {
    color[source] = "gray";
    for (auto child : adj_list[source]) {
        if (color[child] == "white") {
            DFS(child);
        }
    }
    color[source] = "black";
    insert_first(source);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        color[x] = "white";
        if (y != "Nill") {
            color[y] = "white";
        }else
        {
            color[y] = "red";
        }
        
        
    }
    for(auto node:color)
    {
        if(node.second=="white")
        {
            DFS(node.first);
        }
    }
    cout<<"The graph is: "<<endl;
    for(auto node:adj_list)
    {
        cout<<node.first<<"->";
        for(auto child:node.second)
        {
            cout<<child<<" ";
        }
        cout<<endl;
    }
    cout<<"The topological sort is: ";
    printlist();
    adj_list.clear();
}
