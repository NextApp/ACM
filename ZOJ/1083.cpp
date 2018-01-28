#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
char M[40][40];
int vis[40][40];
int m,n,t;
char W[20000][40];
int judge(int &a1,int &b1,int &a2,int &b2,char c)
{
    a1=1000,b1=1000,a2=0,b2=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(M[i][j]==c)
            {
                a1=min(i,a1);
                b1=min(j,b1);
                a2=max(i,a2);
                b2=max(j,b2);
            }
    for(int y=b1; y<=b2; y++)
        if(!(M[a1][y]==c||vis[a1][y]==-1))return 0;
        else if(!(M[a2][y]==c||vis[a2][y]==-1))return 0;
    for(int x=a1; x<=a2; x++)
        if(!(M[x][b1]==c||vis[x][b1]==-1))return 0;
        else if(!(M[x][b2]==c||vis[x][b2]==-1))return 0;
    return 1;

}
char V[150],T[150];
char S[40];
int cmp(const void*_a,const void*_b)
{
    char *a=(char*)_a;
    char *b=(char*)_b;
    return strcmp(a,b);
}
int dfs(int l)
{
    int ok=0;
    for(char c='A'; c<='Z'; c++)
        if(!V[c]&&T[c])
        {
            ok=1;
            int a1,a2,b1,b2;
            if(judge(a1,b1,a2,b2,c))
            {
                S[l]=c;
                for(int y=b1; y<=b2; y++)
                {
                    if(M[a1][y]==c)vis[a1][y]=-1;
                    if(M[a2][y]==c)vis[a2][y]=-1;
                }
                for(int x=a1; x<=a2; x++)
                {
                    if(M[x][b1]==c)vis[x][b1]=-1;
                    if(M[x][b2]==c)vis[x][b2]=-1;
                }
                V[c]=1;
                dfs(l+1);
                V[c]=0;
                for(int y=b1; y<=b2; y++)
                {
                    if(M[a1][y]==c)vis[a1][y]=0;
                    if(M[a2][y]==c)vis[a2][y]=0;
                }
                for(int x=a1; x<=a2; x++)
                {
                    if(M[x][b1]==c)vis[x][b1]=0;
                    if(M[x][b2]==c)vis[x][b2]=0;
                }
            }
        }
    if(!ok)
    {
        int o=0;
        for(int i=l-1; i>=0; i--)
            W[t][o++]=S[i];
        W[t][o]='\0';

        t++;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        t=0;
        memset(vis,0,sizeof(vis));
        memset(T,0,sizeof(T));
        for(int i=0; i<m; i++)
            scanf("%s",M[i]);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(M[i][j]!='.')T[M[i][j]]=1;
        memset(V,0,sizeof(V));
        dfs(0);
        qsort(W,t,sizeof(W[0]),cmp);
        for(int i=0; i<t; i++)
            printf("%s\n",W[i]);
    }
    return 0;
}
