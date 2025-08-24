#include<bits/stdc++.h>
using namespace std;

int lowerB(vector<int>& v, int f) {
    int l = 0;
    int h = v.size() - 1;
    int ans = -1;
    while (l <= h) {
        int mid = (h + l) / 2;
        if (v[mid] >= f) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upperB(vector<int>& v, int f) {
    int l = 0;
    int h = v.size() - 1;
    int ans = -1;
    while (l <= h) {
        int mid = (h + l) / 2;
        if (v[mid] > f) {
            h = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int f;
    cin >> f;
    int lb = lowerB(v, f);
    if (lb!= -1) {
        cout << lb << " " << v[lb] << endl;
    } else {
        cout << "Lower bound not found" << endl;
    }
    int hb = upperB(v, f);
    if (hb!= -1) {
        cout << hb << " " << v[hb] << endl;
    } else {
        cout << "Upper bound not found" << endl;
    }
    return 0;
}