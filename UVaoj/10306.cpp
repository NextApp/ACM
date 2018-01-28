#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000000
using namespace std;
int n,S,d[320][320],a[120],b[120];
int main()
{
    int T;
    freopen("1.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>n>>S;
        memset(d,0,sizeof(d));
        int m=INF;
        for(int i=0; i<n; i++)
        {
            cin>>a[i]>>b[i];
            if(a[i]*a[i]+b[i]*b[i]==S*S)m=1;
            d[a[i]][b[i]]=1;
        }
        for(int i=0; i<=S; i++)
            for(int j=0; j<=S; j++)
            {
                if(i*i+j*j>S*S)continue;
                for(int k=0; k<n; k++)
                {
                    int x=i+a[k],y=j+b[k];
                    if(x*x+y*y<=S*S&&d[i][j])
                    {
                        if(!d[x][y])d[x][y]=d[i][j]+1;
                        else d[x][y]=min(d[x][y],d[i][j]+1);
                        if(x*x+y*y==S*S)m=min(m,d[x][y]);
                    }
                }
            }
        if(m==INF)cout<<"not possible"<<endl;
        else cout<<m<<endl;
    }
    return 0;
}
