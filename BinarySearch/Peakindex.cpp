#include<bits/stdc++.h>
using namespace std;
queue<int>q2;
void print(queue<int> q1)
{
    int x=q1.front();
    q1.pop();
    if (q1.empty())
    {
        q2.push(x);
        return ;
    }
    print(q1);
    q2.push(x);
}

int main()
{
    queue<int>q1;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        q1.push(x);
    }
    print(q1);
    while (!q2.empty())
    {
        cout<<q2.front()<<" ";
        q2.pop();
    }
    

}