#include <bits/stdc++.h>
using namespace std;

void merge(int ar[], int l, int mid, int r) {
    int n1 = mid - l + 1; 
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++) {
        a[i] = ar[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = ar[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            ar[k] = a[i];
            k++;
            i++;
        } else {
            ar[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1) {
        ar[k] = a[i];
        i++;
        k++;
    }
    while (j < n2) {
        ar[k] = b[j];
        j++;
        k++;
    }
}

void divider(int ar[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        divider(ar, l, mid);
        divider(ar, mid + 1, r);
        merge(ar, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    divider(ar, 0, n - 1);
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
    return 0;
}
