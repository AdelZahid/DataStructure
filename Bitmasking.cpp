#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> masks(n,0);
    for (int i = 0; i < n; i++)
    {
        int num_days;
        cin>>num_days;
        int mask=0;
        for (int j = 0; j <num_days ; j++)
        {
            int day;
            cin>>day;
            mask=(mask | (1<<day));
        }
        masks[i]=mask;
    }
    int maxdays=0;
    int p1=-1;
    int p2=-2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int intsec=(masks[i] & masks[j]);
            int comon_days=__builtin_popcount(intsec);
            cout<<i<<" "<<j<< " "<<comon_days<<endl;
        }
    }
}