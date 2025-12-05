#include <bits/stdc++.h>
using namespace std;

void Search(vector<int> &V, int K)
{
    int l = 0;
    int h = V.size();
    while (h - l > 1)
    {
        int mid = (l + h) / 2;
        if (V[mid] > K)
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
    }
    int neg=0;
    if (V[l]>K)
    {
        neg= (V.size()-l);
    }else if (V[l]==K || V[h]==K)
    {
        cout<<'0'<<endl;
        return;
    }else
    {
        neg=(V.size()-h);
    }
    if (neg%2==0)
    {
        cout<<"POSITIVE"<<endl;
    }else
    {
        cout<<"NEGATIVE"<<endl;
    }
}

int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<int> V;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        V.push_back(x);
    }
    sort(V.begin(),V.end());
    while (Q--)
    {
        int x;
        cin>>x;
        Search(V,x);
    }
    
}