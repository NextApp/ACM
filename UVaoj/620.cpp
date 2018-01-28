#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1200
using namespace std;
int n,d[N][N][3],vis[N][N];
char M[N];
int ok=0;
char V[5][20]={"SIMPLE","FULLY-GROWN","MUTAGENIC","MUTANT"};
int dp(int i,int j)
{
    if(vis[i][j])return 0;
    vis[i][j]=1;
    if(j-i==1)
    {
        if(M[i]=='A')
        {
            d[i][j][0]=1,d[i][j][1]=1;
            ok=0;
        }
        else if(M[i]=='O')d[i][j][0]=1;
        else d[i][j][2]=1;
    }
    else if(j-i>2)
    {
        for(int k=i+1; k<j; k++)
        {
            for(int u=k+1; u<=j; u++)
            {
                dp(i,k);
                dp(k,u);
                dp(u,j);
                if(d[i][k][0]&&d[k][u][1]&&d[u][j][2])
                {
                    d[i][j][0]=1;
                    ok=1;
                }
                if(d[i][k][2]&&d[k][u][0]&&d[u][j][1])
                {
                    d[i][j][0]=1;
                    ok=2;
                }
            }
        }
    }
}
int main()
{
    int T;
   // freopen("1.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>M;
        n=strlen(M);
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        ok=0;
        dp(0,n);
        if(d[0][n][0])cout<<V[ok]<<endl;
        else cout<<V[3]<<endl;
    }
    return 0;
}
