#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[15][15][15];
int main()
{
    int m,n,d,T;
    cin>>T;
    memset(a,0,sizeof(a));
    a[1][1][1]=1;
    for(int i=2; i<=13; i++)
        for(int j=1; j<=i; j++)
            for(int k=1; k<=i; k++)
                a[i][j][k]=a[i-1][j-1][k]+a[i-1][j][k-1]+(i-2)*a[i-1][j][k];
    while(T--)
    {
        cin>>m>>n>>d;
        cout<<a[m][n][d]<<endl;
    }
    return 0;
}
