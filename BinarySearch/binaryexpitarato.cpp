#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
long long int multipie(long long a,long long b)
{
    int ans=0;
    while (b>0)
    {
        if (b&1)
        {
            ans=(ans+a)%M;
        }
        a=(a+a)%M;
        b>>=1;
    }
    return ans;
}
long long int power (long long int a,long long int b)
{
    int ans=1; 
    while (b)
    {
        if (b&1)
        {
            ans=multipie(ans,a);
        }
        a=multipie(a,a);
        b>>=1;
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<power(n,m);
}