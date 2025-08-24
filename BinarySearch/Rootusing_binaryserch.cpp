#include <bits/stdc++.h>
using namespace std;

int Root(int l, int n) {
    int h = n;
    int ans = 0;
    while (l <= h) {
        int mid = (h + l) / 2;
        if (mid * mid <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int r = Root(1, n);
    cout << r << endl;
    return 0;
}
