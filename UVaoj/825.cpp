#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define N 1200
using namespace std;
int vis[N][N];
long long d[N][N];
char b[1200];
int m,n;
int main()
{
   // freopen("1.txt","r",stdin);
    int T,O=0;
    cin>>T;
    while(T--)
    {
        if(O)cout<<endl;
        O=1;
        cin>>m>>n;
        memset(vis,0,sizeof(vis));
        int k,ok;
        for(int i=0; i<m; i++)
        {
            cin>>k;
            gets(b);
            ok=0;
            k=0;
            for(int j=0; b[j]; j++)
            {
                if(b[j]<='9'&&b[j]>='0')k=10*k+b[j]-'0',ok=1;
                if((b[j+1]<'0'||b[j+1]>'9')&&ok)
                    vis[i][k-1]=-1,k=0,ok=0;
            }
        }
        if(!vis[0][0])
        {
            d[0][0]=1;
            for(int i=1; i<m; i++)
                if(vis[i][0]!=-1)d[i][0]=d[i-1][0];
                else d[i][0]=0;
            for(int i=1; i<n; i++)
                if(vis[0][i]!=-1)d[0][i]=d[0][i-1];
                else d[0][i]=0;
            for(int i=1; i<m; i++)
                for(int j=1; j<n; j++)
                    if(vis[i][j]!=-1)d[i][j]=d[i][j-1]+d[i-1][j];
                    else d[i][j]=0;
            cout<<d[m-1][n-1]<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
