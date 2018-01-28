#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 1200
using namespace std;
struct T
{
    int x,y,w;
} q[N];
int n,m,k,OK;
int cmp(const void *_a,const void*_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return a->w<b->w;
}
void dfs(int cur,int add,int p)
{
    if(OK)return ;
    if(add)
    {
        int ok=1;
        for(int i=p+1; i<m; i++)
        {
            if(cur==q[i].x)
            {
                dfs(q[i].y,add,i);
                ok=0;
            }
            else if(cur==q[i].y)
            {
                dfs(q[i].x,add,i);
                ok=0;
            }
            if(!ok)break;
        }
        if(ok&&cur==1)OK=1;
    }
    else
    {
        int ok=0;
        for(int i=p+1; i<=m&&!OK; i++)
        {
            if(i==m)
            {
                if(cur==2)OK=1;
                continue;
            }
            if(cur>0)dfs(cur-1,1,i-1);
            if(cur<n)dfs(cur+1,1,i-1);
            if(cur==q[i].x)
            {
                dfs(q[i].y,add,i);
                ok=1;
            }
            else if(cur==q[i].y)
            {
                dfs(q[i].x,add,i);
                ok=1;
            }
            if(ok)break;
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        OK=0;
        for(int i=0; i<m; i++)
            cin>>q[i].x>>q[i].y>>q[i].w;
        qsort(q,m,sizeof(q[0]),cmp);
        dfs(k,0,-1);
        if(OK)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
