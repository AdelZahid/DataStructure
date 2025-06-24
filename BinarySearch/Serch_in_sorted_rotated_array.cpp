#include<bits/stdc++.h>
using namespace std;
vector<int>arr;

int rotated_array_search(int low,int hi,int tar)
{
    
    while (low<=hi)
    {
        int mid=(low+hi)/2;
        if (arr[mid]==tar)
        {
            return mid;
        }
        if (arr[low]<=arr[mid])
        {
            if (arr[low]<=tar && tar<=arr[mid])
            {
                hi=mid-1;
            }else
            {
                low=mid+1;
            }
        }
        else
        {
            if (arr[mid]<=tar && tar<=arr[hi])
            {
                low=mid+1;
            }else
            {
                hi=mid-1;
            }
            
            
        }
        
        
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int T;
    cin>>T;
    int ind=rotated_array_search(0,n-1,T);
    if (ind!=-1)
    {
        cout<<"Found at index: "<<ind<<" The num: "<<arr[ind]<<endl;
    }else
    {
        cout<<"dosent exist "<<endl;
    }
    
    
}