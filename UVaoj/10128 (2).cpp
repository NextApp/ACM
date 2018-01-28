#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[15][15][15];
int Cmn(int m,int n)
{
    if(m==0)return 1;
    m=n-m>m?m:n-m;
    int s=1;
    for(int t=0;t<m;t++)
    {
        s*=n-t;
        s/=t+1;
    }
    return s;
}
int search(int n,int b)
{
    int s=0;
    for(int i=0;i<=n;i++)s+=a[n][b][i];
    for(int j=0;j<=n;j++)s+=a[n][j][b];
    return s-a[n][b][b];
}
int main()
{
    memset(a,0,sizeof(a));
    a[1][1][1]=1;
    for(int i=2;i<=13;i++)
    for(int j=1;j<=(i+1)/2;j++)
    for(int k=j;k+j-1<=i;k++)
    {
       if(j==1&&k==1)continue;
        int t=0;
        for(int m=j-1;i-m>=k;m++)
            {
                if(j==1&&m>j-1)continue;
                int e=search(m,j-1);
                int d=search(i-m-1,k-1);
                if(!e)e=1;
                if(!d)d=1;
                t+=Cmn(m,i-1)*e*d;
            }
        a[i][j][k]=t;
    }
    int T;cin>>T;
    while(T--)
    {
        int m,n,k;
        cin>>m>>n>>k;
        if(n>k)cout<<a[m][k][n]<<endl;
        else cout<<a[m][n][k]<<endl;
    }
    return 0;
}
