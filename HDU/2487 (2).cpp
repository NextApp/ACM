#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x1,y1,x2,y2;
int m,n,vis[150];
char M[120][120];
int search(char a)
{
    int ok=0;
    x1=120,y1=0,x2=0,y2=120;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        if(a==M[i][j])
        {
            ok=1;
            x1=min(i,x1);
            y1=max(j,y1);
            x2=max(i,x2);
            y2=min(j,y2);
        }
    }
    return ok;
}
void dfs()
{
    for(char a='A';a<='Z';a++)
    {
      if(search(a))
      {
          int ok=1;
          for(int i=y1;i<=y2;i++)
          if(M[x1][i]!=a)ok=0;
          for(int i=y1;i<=y2;i++)
          if(M[x2][i]!=a)ok=0;
          for(int i=x1;i<=x2;i++)
          if(M[i][y1]!=a)ok=0;
          for(int i=x1;i<=x2;i++)
          if(M[i][y2]!=a)ok=0;
          for(int i=x1+1;i<x2;i++)
          for(int j=y2+1;j<y1;j++)
          if(M[i][j]!='.')ok=0;
          if(x2-x1<=1)ok=0;
          if(y1-y2<=1)ok=0;
          if(ok)vis[a]=1;
      }
    }
}
int main()
{
  //  freopen("1.txt","r",stdin);
    while(scanf("%d%d",&m,&n)==2)
    {
        if(!m&&!n)return 0;
        for(int i=0;i<m;i++)
        scanf("%s",M[i]);
        memset(vis,0,sizeof(vis));
        dfs();
        for(char i='A';i<='Z';i++)
            if(vis[i])printf("%c",i);
        printf("\n");
    }
    return 0;
}
