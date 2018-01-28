#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int end,n,C[25],tot,vis[25],V[25];
struct T
{
    int n,a[25],v[25];
} M[25];
int dfs(int cur,int k)
{
    if(cur==end)
    {
        tot++;
        for(int j=0; j<k-1; j++)
            cout<<C[j]<<' ';
        cout<<end<<endl;
    }
    else for(int i=0; i<M[cur].n; i++)
        {
            int m=M[cur].a[i];
            if(!vis[m]&&V[m])
            {
                vis[m]=1;
                C[k]=m;
                dfs(m,k+1);
                vis[m]=0;
            }
        }
}
int Dfs(int cur)
{
    for(int i=0; i<M[cur].n; i++)
    {
        int m=M[cur].a[i];
        if(!V[m])
        {
            V[m]=1;
            Dfs(m);
        }
    }
}
int cmp(const void *_a,const void *_b)
{
    int *a=(int*)_a;
    int *b=(int*)_b;
    return *a-*b;
}
int main()
{
   //freopen("1.txt","r",stdin);
    int id=1;
    while(cin>>end)
    {
        n=0;
        tot=0;
        int a,b;
        for(int i=0; i<22; i++)
        {
            M[i].n=0;
            memset(M[i].v,0,sizeof(M[i].v));
        }
        memset(vis,0,sizeof(vis));
        memset(V,0,sizeof(V));
        while(cin>>a>>b)
        {
            if(!a&&!b)break;
            else
            {
                if(!M[a].v[b])
                {
                    M[a].a[M[a].n++]=b;
                    M[a].v[b]=1;
                }
                if(!M[b].v[a])
                {
                    M[b].a[M[b].n++]=a;
                    M[b].v[a]=1;
                }
                n=a>n?a:n;
                n=b>n?b:n;
            }
        }
        for(int i=0; i<=n; i++)
            qsort(M[i].a,M[i].n,sizeof(M[i].a[0]),cmp);
        cout<<"CASE "<<id++<<":"<<endl;
            vis[1]=1;
            V[end]=1;
            C[0]=1;
            Dfs(end);
            dfs(1,1);
        cout<<"There are "<<tot<<" routes from the firestation to streetcorner "<<end<<"."<<endl;
    }
    return 0;
}
