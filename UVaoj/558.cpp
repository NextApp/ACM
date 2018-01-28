#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 100000000
#define N 2200
using namespace std;
int d[N];
int n,m,x[N],y[N],r[N];
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
            cin>>x[i]>>y[i]>>r[i];
        for(int i=1; i<n; i++)d[i]=INF;
        d[0]=0;
        for(int k=0; k<n-1; k++)
            for(int i=0; i<m; i++)
            {
                int u=x[i],v=y[i];
                if(d[u]<INF)d[v]=min(d[v],d[u]+r[i]);
            }
        int ok=0;
        for(int i=0; i<m; i++)
        {
            int u=x[i],v=y[i];
            if(d[u]<INF&&d[v]>d[u]+r[i])
            {
                ok=1;
                break;
            }
        }
        if(ok)cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
    return 0;
}
