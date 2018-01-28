#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct T
{
    int n,a[105];
} A[120];
int n,C[120],maxnum,V[120];
int dfs(int cur,int m)
{
    if(m>maxnum)
    {
        maxnum=m;
        for(int i=1; i<=n; i++)V[i]=C[i];
    }
    if(cur<=n)
    {
        for(int i=cur; i<=n; i++)
            if(!C[i])
            {
                int ok=1;
                for(int j=0; j<A[i].n; j++)
                    if(C[A[i].a[j]]==1)
                    {
                        ok=0;
                        break;
                    }
                if(ok)
                {
                    C[i]=1;
                    int D[120],k=0;
                    for(int j=0; j<A[i].n; j++)
                    {
                        int m=A[i].a[j];
                        if(!C[m])
                        {
                            C[m]=-1;
                            D[k++]=m;
                        }
                    }
                    dfs(i+1,m+1);
                    for(int j=0; j<k; j++)
                        C[D[j]]=0;
                }
                else
                {
                    C[i]=-1;
                    dfs(i+1,m);
                }
                C[i]=0;
            }
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int num,m;
    cin>>num;
    while(num--)
    {
        cin>>n>>m;
        memset(C,0,sizeof(C));
        for(int i=1; i<=n; i++)A[i].n=0;
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            A[x].a[A[x].n++]=y;
            A[y].a[A[y].n++]=x;
        }
        maxnum=0;
        dfs(1,0);
        cout<<maxnum<<endl;
        int o=1;
        for(int i=1; i<=n; i++)
            if(V[i]==1)
            {
                if(o++<maxnum)cout<<i<<' ';
                else cout<<i<<endl;
            }
    }
    return 0;
}
