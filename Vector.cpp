
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void printvec(vector<int> &v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cout << "Enter the number of vectors: ";
    cin >> N;

    vector<vector<int>> v;  // Use a vector of vectors instead of an array of vectors

    for (int i = 0; i < N; i++)
    {
        int n;
        cout << "Enter size of vector " << i + 1 << ": ";
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
     v.push_back(vector<int>());
    cout << "Printing vectors:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Vector " << i + 1 << ": ";
        printvec(v[i]);
    }
        cout<<v[0][1];
    return 0;
}
