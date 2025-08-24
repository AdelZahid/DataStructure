#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char A,char B,char C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout<<A<<" -> TO -> "<<C<<endl;
        TOH(n-1,B,A,C);
    }
    return;
}
void hanoi_4_towers(int n, char source, char auxiliary1, char auxiliary2, char destination) {
    if (n == 0) return;
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    int m = n / 2;
    hanoi_4_towers(n - m, source, destination, auxiliary2, auxiliary1);
    hanoi_4_towers(m, source, auxiliary1, auxiliary2, destination);
    hanoi_4_towers(n - m, auxiliary1, source, auxiliary2, destination);
}

int main()
{
    int n;
    cin>>n;
    TOH(n,'p','Q','R');
    hanoi_4_towers(n,'A','B','C','D');
    return 0;
}