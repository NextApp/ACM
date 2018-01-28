#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,f[301][301][9][9];
void EMQ()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&f[i][j][0][0]);
    int k=log((double)n)/log(2.0);
    for(int i=0; i<=k; i++)
        for(int x=0; x<=k; x++)
        {
            if(!i&&!x)continue;
            for(int j=1; j+(1<<i)-1<=n; j++)
                for(int y=1; y+(1<<x)-1<=n; y++)
                {
                    if(!i)f[j][y][i][x]=min(f[j][y][i][x-1],f[j][y+(1<<(x-1))][i][x-1]);
                    else f[j][y][i][x]=min(f[j][y][i-1][x],f[j+(1<<(i-1))][y][i-1][x]);
                }
        }

}
int Emq(int x,int y,int x1,int y1)
{
    int k1=log(double(y-x+1))/log(2.0);
    int k2=log(double(y1-x1+1))/log(2.0);
    int u=f[x][x1][k1][k2];
    int l=f[y-(1<<k1)+1][x1][k1][k2];
    int r=f[x][y1-(1<<k2)+1][k1][k2];
    int t=f[y-(1<<k1)+1][y1-(1<<k2)+1][k1][k2];
    return min(min(l,r),min(u,t));
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        EMQ();
        int m;
        scanf("%d",&m);
        int x,y,x1,y1;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&x,&y,&x1,&y1);
            printf("%d\n",Emq(x,x1,y,y1));
        }
    }
    return 0;
}
