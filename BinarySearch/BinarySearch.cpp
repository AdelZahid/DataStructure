#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
void binarySearch(int low,int hi,int t)
{
    int mid=(low+hi)/2;
    while (low<=hi)
    {
        if (arr[mid]<t)
        {
            low=mid+1;
        }else if (arr[mid]>t)
        {
            hi=mid-1;
        }
        else
        {
            cout<<"Element is present at index "<<mid<<" :"<<arr[mid]<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}
int main()
{
        int n,t;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cin>>t;
    binarySearch(0,n-1,t);
}