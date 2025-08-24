#include<bits/stdc++.h>
using namespace std;
double eps=1e-6;
int main()
{
    double x;
    cin>>x;
    double l=1,h=x,mid;
    while ((h-l)>eps)
    {
        mid= (l+h)/2;
        if (mid*mid<x)
        {
            l=mid;
        }else
        {
            h=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}