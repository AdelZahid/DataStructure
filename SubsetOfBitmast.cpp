#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& num)
{
    int n=num.size();
    int sub_ct=(1<<n);
    vector<vector<int>>subsets;
    for (int  mask= 0; mask < sub_ct; mask++)
    {
        vector<int>subset;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
               subset.push_back(num[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    auto allsubsets=subsets(v);
    for(auto subset:allsubsets)
    {
        for(int ele:subset)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
}