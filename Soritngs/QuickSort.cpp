#include<bits/stdc++.h>
using namespace std;
vector<int>V;
int partition(int low,int hi)
{
    int i=low;
    int j=hi;
    int pivot=V[low];
    while (i<j)
    {
        while (V[i]<=pivot)
        {
            i++;
        }
        while (V[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            swap(V[i],V[j]);
        }
    }
    swap(V[low],V[j]);
    return j;
}
void Quick_Sort(int low,int hi)
{
    if (low<hi)
    {
        int p=partition(low,hi);
        Quick_Sort(low,p-1);
        Quick_Sort(p+1,hi);
    }
    
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        V.push_back(x);
    }
    Quick_Sort(0,n-1);
    for(auto &i:V)
    {
        cout<<i<<" ";
    }

}