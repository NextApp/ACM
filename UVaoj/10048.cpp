#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 200000000
using namespace std;
int d[120][120];
int main()
{
    //freopen("1.txt","r",stdin);
    int C,S,Q,id=0;
    while(cin>>C>>S>>Q)
    {
        if(!C&&!S&&!Q)break;
        else
        {
            if(id)cout<<endl;
            memset(d,0,sizeof(d));
            cout<<"Case #"<<++id<<endl;
            for(int i=0;i<S;i++)
            {
                int x,y,r;
                cin>>x>>y>>r;
                d[y][x]=d[x][y]=r;
            }
            for(int i=1;i<C;i++)
            for(int j=i+1;j<=C;j++)
                if(!d[i][j])d[j][i]=d[i][j]=INF;
            for(int k=1;k<=C;k++)
            for(int i=1;i<=C;i++)
            for(int j=1;j<=C;j++)
            {
                int t=max(d[i][k],d[k][j]);
                d[i][j]=min(t,d[i][j]);
            }
            for(int i=0;i<Q;i++)
            {
                int x,y;
                cin>>x>>y;
                if(d[x][y]<INF)cout<<d[x][y]<<endl;
                else cout<<"no path"<<endl;
            }
        }
    }
    return 0;
}
