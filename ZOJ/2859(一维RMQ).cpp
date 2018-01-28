#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 305
#define INF (1<<31)-1
using namespace std;
int n,a[maxn][maxn],f[maxn][maxn][10];
double Log2=log(2.0);
int Emq(int cur,int i,int j)
{
    int k=(int)(log(double(j-i+1))/Log2);
    return min(f[cur][i][k],f[cur][j-(1<<k)+1][k]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int s=(int)(log((double)n)/Log2);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&f[i][j][0]);
            for(int j=1; j<=s; j++)
                for(int k=0; k+(1<<j)-1<n; k++)
                        f[i][k][j]=min(f[i][k][j-1],f[i][k+(1<<(j-1))][j-1]);
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int x1,y1,x2,y2,mm=INF;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1--,y1--,x2--,y2--;
            for(int j=x1;j<=x2;j++)
                mm=min(Emq(j,y1,y2),mm);
            printf("%d\n",mm);
        }

    }
    return 0;
}
