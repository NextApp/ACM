#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,vset[40],v[40],c,nm,vis[40],s[40];
struct T
{
    int a[40],n;
} A[40];
void set(int cur)
{
    nm++;
    vset[cur]=c;
    for(int i=0; i<A[cur].n; i++)
        if(!vset[A[cur].a[i]])set(A[cur].a[i]);
}
int search(int cur)
{
    for(int i=0; i<A[cur].n; i++)
    {
        int a=A[cur].a[i];
        if(vset[a]==c&&!s[a]&&!vis[a])
        {
            s[a]=1;
            search(a);
        }
    }
}
int judge(int cur)
{
    int num=0;
    for(int i=0; i<A[cur].n; i++)
    {
        int a=A[cur].a[i];
        if(vset[a]==c&&!vis[a])
        {
            num=1;
            break;
        }
    }
    if(!vis[cur])num=1;
    return num;
}
int E[100],o;
void print_subet(int cur)
{
    int t=cur!=1?E[cur-1]+1:1;
    for(int r=t; r<=n; r++)
        if(vset[r]==c&&judge(r))
        {
            E[cur]=r;
            int count[40],k=0;
            for(int x=0; x<A[r].n; x++)
            {
                int y=A[r].a[x];
                if(vset[y]==c&&!vis[y])
                {
                    vis[y]=1;
                    count[k++]=y;
                }
            }
            if(!vis[r])count[k++]=r,vis[r]=1;
            int sum=0;
            memset(s,0,sizeof(s));
            for(int i=1; i<=n; i++)
                if(vset[i]==c&&!vis[i]&&!s[i])
                {
                    s[i]=1;
                    search(i);
                    sum++;
                }
            if(!sum)nm=cur>nm?nm:cur;
            if(sum+cur<nm)print_subet(cur+1);
            for(int x=0; x<k; x++)
                vis[count[x]]=0;
        }
}
int main()
{
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m)return 0;
        else
        {
            for(int i=1; i<=n; i++)
                A[i].n=0;
            c=1;
            for(int i=1; i<=n; i++)
                vset[i]=vis[i]=0;
            int x,y;
            for(int i=0; i<m; i++)
            {
                scanf("%d%d",&x,&y);
                A[x].a[A[x].n++]=y;
                A[y].a[A[y].n++]=x;
            }
            int sum=0;
            for(int i=1; i<=n; i++)
                if(!vset[i])
                {
                    nm=0;
                    set(i);
                    print_subet(1);
                    sum+=nm;
                    c++;
                }
            cout<<sum<<endl;
        }
    }
    return 0;
}
