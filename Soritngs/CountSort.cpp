
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int maxc = INT32_MIN;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        maxc = max(maxc, ar[i]);
    }
    vector<int> arc(maxc + 1, 0);
    for (int i = 0; i < n; i++)
    {
        arc[ar[i]]++;
    }
    for (int i = 1; i <= maxc; i++)
    {
        arc[i] += arc[i - 1];
    }
    vector<int> out(n);
    for (int i = n - 1; i >= 0; i--)
    {
        out[--arc[ar[i]]] = ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}
