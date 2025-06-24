#include<bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int>&V)
{
    int n=V.size();
    for (int i = 1; i <=n-1; i++)
    {
        int cur=V[i];
        int j=i-1;
        while(V[j]>cur && j>=0)
        {
            V[j+1]=V[j];
            j--;
        }
        V[j+1]=cur;
    }
    
}

int main()
{
    vector<int>V;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        V.push_back(x);
    }
    insertion_sort(V);
    for(auto &i:V)
    {
        cout<<i<<" ";
    }
}