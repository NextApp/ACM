#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 100000000
using namespace std;
int d[120][120];
int main()
{
    int n,m,id=1;
    while(cin>>n>>m)
    {
        if(!n&&!m)break;
        else
        {
            memset(d,0,sizeof(d));
            for(int i=0; i<m; i++)
            {
                int x,y,r;
                cin>>x>>y>>r;
                d[x][y]=d[y][x]=r;
            }
            for(int i=1; i<=n; i++)
                for(int j=i+1; j<=n; j++)
                    if(!d[i][j])d[i][j]=d[j][i]=-INF;
            for(int k=1; k<=n; k++)
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                    {
                        int o=min(d[i][k],d[k][j]);
                        d[i][j]=max(d[i][j],o);
                    }
            int S,E,R;
            cin>>S>>E>>R;
            cout<<"Scenario #"<<id++<<endl;
            d[S][E]--;
            R=R%d[S][E]==0?R/d[S][E]:R/d[S][E]+1;
            cout<<"Minimum Number of Trips = "<<R<<endl<<endl;
        }
    }
    return 0;
}
