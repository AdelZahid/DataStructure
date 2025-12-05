#include<bits/stdc++.h>
using namespace std;
vector<int> Matx_P(20,0);
int Matx_Cost[100][100];
int Matx_K[100][100];

void MCM(int len){
    int n=len;

    for(int i=1;i<=n;i++){
        Matx_Cost[i][i]=0;
    }

    int j=0,q=0;

    for(int l=2;l<=n;l++){
        for(int i=1;i<=(n-l+1);i++){
            j=i+l-1;
            Matx_Cost[i][j]=INT_MAX;
            for(int k=i;k<=(j-1);k++){
               q=Matx_Cost[i][k]+Matx_Cost[k+1][j]+(Matx_P[i-1]*Matx_P[k]*Matx_P[j]);
               if(q<Matx_Cost[i][j]){
                Matx_Cost[i][j]=q;
                Matx_K[i][j]=k;
               }
            }
        }
    }
    
}


void optimal_pairs(int i,int j){
    if(i==j){
        cout<<"A"<<i;
    }else{
        cout<<"( ";
        optimal_pairs(i,Matx_K[i][j]);
        optimal_pairs(Matx_K[i][j]+1,j);
        cout<<" ) ";
    }
}

int main()
{
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        Matx_P[i]=r;
    }
    MCM(n);
    optimal_pairs(1,n);
    return 0;
}