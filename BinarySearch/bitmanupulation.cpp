#include <bits/stdc++.h>
using namespace std;
void printBinar(int num)
{
    for (int i = 10; i>=0; i--)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main()
{
    freopen("output.txt","w",stdout);
    int a=10;
    int i=2;
    if ((a & (1<<i))!=0)
    {
        cout<<"Set bit"<<endl;
    }else
    {
        cout<<"Not set bit"<<endl;
    }
    printBinar(a);
    //setbit
    printBinar(a | (1<<i));
    //unset bit
    printBinar(a&(~(1<<i)));
    // toggle bit
    printBinar(a^ (1<<i));
    //count setbit
    cout<<__builtin_popcount(a)<<endl;
    // divide using bit
    cout<<(a>>1)<<endl;
    // multipie using bit
    cout<<(a<<1)<<endl;
    // for character bit representation
    for (char i = 'A'; i <='E'; i++)
    {
        cout<<i<<endl;
        printBinar(int(i));
    }
    for (char i = 'a'; i <='e'; i++)
    {
        cout<<i<<endl;
        printBinar(int(i));
    }
    // character convert uper,lower vice-versa
    char ch='A';
    /*to convert upper chase character to 
    lower chase character set 1 bit int the
    5 th possition of the binary turm of the
    character*/
    cout<<(char)(ch | (1<<5))<<endl;
    char ch2='e';
    /*to convert lower case character to
    upper chase character unset the 5th bit
    from the binary representation of the
    character */
    cout<<(char)(ch2 & (~(1<<5)))<<endl;
    /*(1<<5) is the binary for space " " */
    cout<<char('C' | ' ')<<endl;
    /*~(1<<5) is the binary of underscore '_' */
    cout<<char('c' & '_')<<endl;
    /* check if number is power of 2*/
    int n;
    cin>>n;
    if(n&(n-1)){
        cout<<"NO";
    }else
    {
        cout<<"YES";
    }
    
    
} 
