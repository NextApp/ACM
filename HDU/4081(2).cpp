#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define M 1000
#define MAX 1000000000
struct piont
{
    double x,y;
} pnt[M];

int n,m,pre[M],stack[M],ren[M];

double ans,g[M][M],max1[M][M],d[M];

bool flag[M];      //max1[i][j]表示i 到j路径上最大边的值

double bian(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void prim()
{
    memset(flag,0,sizeof(flag));
    flag[1]=1;
    for(int i=2; i<=n; i++)
    {
        pre[i]=1;
        d[i]=g[1][i];
    }
    d[1]=0;
    ans=0;
    int top=0;
    stack[top++]=1;          //保存最小生成树上的节点
    for(int i=1; i<n; i++)
    {
        double tmp=MAX;
        int t=1;
        for(int j=2; j<=n; j++)
        {
            if(!flag[j]&&d[j]&&d[j]<tmp)
            {
                t=j;
                tmp=d[j];
            }
        }
        flag[t]=true;
        ans+=tmp;
        for(int i=0; i<top; i++)  //求出当前找到的节点到最小生长树上每一个点的路径上的最大边
            max1[stack[i]][t]=max1[t][stack[i]]=max(max1[pre[t]][stack[i]],tmp);
        stack[top++]=t;
        for(int j=1; j<=n; j++)
        {
            if(!flag[j]&&g[t][j]&&g[t][j]<d[j])
            {
                d[j]=g[t][j];
                pre[j]=t;   //记录直接前驱
            }
        }
    }
}

int main()
{
    freopen("1.txt","r",stdin);
    int cas,i,j;
    int a,b,c,d,st;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        d=0,st;
        for(i=1; i<=n; i++)
        {
            scanf("%lf%lf%d",&pnt[i].x,&pnt[i].y,&ren[i]);
            if(d<ren[i])
            {
                st=i;
                d=ren[i];
            }
        }
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                g[i][j]=g[j][i]=bian(pnt[i].x,pnt[i].y,pnt[j].x,pnt[j].y);
        prim();
        double ma=0.0;
        for(i=1; i<=n; i++)  //枚举最小生成树外 的边
        {
            if(st!=i)
            {
                if(i==pre[st]||st==pre[i])
                    ma=max(ma,(ren[i]+d)/(ans-g[i][st]));
                else
                    ma=max(ma,(ren[i]+d)/(ans-max1[i][st]));
            }
        }
        printf("%.2f\n",ma);
    }
    return 0;
}
