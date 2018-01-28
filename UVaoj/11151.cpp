#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1200
using namespace std;
int d[N][N];
char m[N];
int dp(int i,int j)
{
    if(j<=i)return d[i][j]=0;
    else if(d[i][j]!=N)return d[i][j];
    else
    {
        if(m[i]==m[j])
        {
            if(j>=i+2)d[i][j]=dp(i+1,j-1);
            else d[i][j]=0;
        }
        else
        {
            if(j-i>=1)
            {
                d[i][j]=min(d[i][j],dp(i,j-1)+1);
                d[i][j]=min(d[i][j],dp(i+1,j)+1);
            }
            else d[i][j]=min(d[i][j],1);
        }
    }
    return d[i][j];
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    getchar();
    while(T--)
    {
        gets(m);
        int n=strlen(m);
        for(int i=0; i<n; i++)
        {
            d[i][i]=0;
            for(int j=i+1; j<n; j++)
                d[i][j]=N;
        }
        dp(0,n-1);
        cout<<n-d[0][n-1]<<endl;
    }
    return 0;
}
