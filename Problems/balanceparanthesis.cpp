#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> symbol = {{'{', -1}, {'[', -2}, {'(', -3}, {'}', 1}, {']', 2}, {')', 3}};
string isbalanc(string s)
{
    stack<char> stk;
    for (char bracket : s)
    {
        if (symbol[bracket] < 0)
        {
            stk.push(bracket);
        }
        else
        {
            if (stk.empty())
            {
                return "NO";
            }
            else
            {
                char top = stk.top();
                stk.pop();
                if (symbol[top] + symbol[bracket])
                {
                    return "NO";
                }
            }
        }
    }
    if (stk.empty())
    {
        return "YES";
    }else
    {
        return"NO";
    }
    
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << isbalanc(s) << endl;
    }
}