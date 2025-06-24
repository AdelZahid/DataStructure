#include<bits/stdc++.h>
using namespace std;



int bs(int arr[],int val, int low , int high)
{
    if(high<=low)
        return(val>arr[low]?(low+1):low);
    int mid=(low+high)/2;
    if(arr[mid]==val)
        return mid+1;
    else if(arr[mid]<val)
        return bs(arr,val,mid+1,high);
    return bs(arr,val,low,mid-1);
}

void insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        int location=bs(arr,key,0,j);
        while(j>=location)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


int main()
{
    vector<int>V;
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertion(arr,n);
    for(auto &i:V)
    {
        cout<<i<<" ";
    }
}