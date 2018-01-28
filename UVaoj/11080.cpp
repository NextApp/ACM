#include<iostream>
#include<cstdio>
#include<cstring>
#define N 240
using namespace std;
int color[N],n,e,a[5],OK;
struct T
{
    int a[N],n;
} A[N];
void dfs(int cur)
{
    for(int i=0; i<A[cur].n&&OK; i++)
    {
        int x=A[cur].a[i];
        if(!color[x])
        {
            int s=3-color[cur];
            a[s]++;
            color[x]=s;
            dfs(x);
        }
        else if(color[x]==color[cur])OK=0;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    scanf("%*d");
    while(scanf("%d%d",&n,&e)==2)
    {
        for(int i=0; i<n; i++)A[i].n=0;
        for(int i=0; i<e; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            A[x].a[A[x].n++]=y;
            A[y].a[A[y].n++]=x;
        }
        memset(color,0,sizeof(color));
        OK=1;
        int sum=0;
        for(int i=0; i<n&&OK; i++)
        {
            if(!color[i])
            {
                a[2]=0;
                color[i]=1;
                a[1]=1;
                dfs(i);
                sum+=a[2]>a[1]?a[1]:a[2];
                if(!a[2])sum+=a[1];
            }
        }
        printf("%d\n",OK?sum:-1);
    }
    return 0;
}
