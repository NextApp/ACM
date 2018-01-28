#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct T
{
    int n,vlaue;
} q[1200000];
int num,n,a[105],half,dif,Left,sum;
bool vis[23005][55];
void check(int v1,int v2,int l)
{
    if(v2<half)
    {
        q[num].vlaue=v1;
        q[num++].n=v2;
    }
    else if(v2==half)
    {
        if(dif>fabs(l))
        {
            dif=fabs(l);
            Left=v1;
        }
    }
    vis[v1][v2]=1;
}
void dfs()
{
    int v1,v2,l,snum,start;
    for(int cur=0; cur<n; cur++)
    {
        snum=num;
        for(int i=snum-1; i>=0; i--)
        {
            v1=q[i].vlaue+a[cur],v2=q[i].n+1;
            l=sum-v1-v1;
            if(!vis[v1][v2]&&n-cur+v2>=half&&-l<dif)check(v1,v2,l);
        }
        v1=a[cur],v2=1;
        l=sum-v1-v1;
        if(!vis[v1][v2]&&n-cur+v2>=half&&-l<dif)check(v1,v2,l);
    }
}
int main()
{
    int T,id=0;
    scanf("%d",&T);
    while(T--)
    {
        if(id)printf("\n");
        id=1;
        memset(vis,false,sizeof(vis));
        num=sum=dif=Left=0;
        scanf("%d",&n);
        half=n/2;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(i<half)Left+=a[i];
        }
        dif=fabs(sum-Left-Left);
        dfs();
        sum-=Left;
        if(sum<Left)Left=sum+Left-(sum=Left);
        printf("%d %d\n",Left,sum);
    }
    return 0;
}
