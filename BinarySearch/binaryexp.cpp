#include<bits/stdc++.h>
using namespace std;

long long int powerbin(int a, int b) {
    if (b == 0) return 1;
    long long int half_pow = powerbin(a, b / 2);
    if (b & 1) {
        return a* half_pow * half_pow;
    } else {
        return  half_pow * half_pow;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << powerbin(n, m);
    return 0;
}
