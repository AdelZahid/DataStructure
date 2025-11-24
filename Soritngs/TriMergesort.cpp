#include <bits/stdc++.h>
using namespace std;
void Merge(int ar[], int l, int m, int r)
{
    int n1 = m - (l + 1);
    int n2 = r - m;
    int a[n1];
    int b[n2];
    for (int i = 0; i <= n2; i++)
    {
        a[i] = ar[i + l];
    }
    for (int i = 0; i <= n2; i++)
    {
        b[i] = ar[i + m+1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i <n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            ar[k] = a[i];
            i++;
            k++;
        }
        else
        {
            ar[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        ar[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ar[k] = b[j];
        j++;
        k++;
    }
}

void divider(int ar[], int l, int r)
{
    int mid = l + (r - l) / 2;
    if (l < r)
    {
        divider(ar, l, mid);
        divider(ar, mid + 1, r);
        Merge(ar, l, mid, r);
    }
    else
    {
        return;
    }
}

int main()
{
   int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }
    divider(ar, 0, n - 1);
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}
