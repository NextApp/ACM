#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N 12000
using namespace std;
int a,b,M[N],q[N],vis[N];
int prim()
{
    memset(M,0,sizeof(M));
    for(int i=2; i<=100; i++)
    {
        if(!M[i])
            for(int j=i+i; j<10000; j+=i)
                M[j]=1;
    }
}
int bfs()
{
    q[0]=b;
    int rear=1,front=0,l[10];
    vis[b]=0;
    while(front<rear)
    {
        int m=q[front++];
        l[1]=m%1000,l[2]=m-((m%1000)/100)*100;
        l[3]=m-((m/10)%10)*10,l[4]=m-m%10;
        for(int i=0;i<=9;i++)
        for(int j=1;j<5;j++)
        {
            if(j==1&&!i)continue;
            int t=l[j]+i*pow(10,4-j);
            if(!M[t]&&vis[t]==-1)
            {
                vis[t]=vis[m]+1;
                q[rear++]=t;
            }
        }
    }
}
int main()
{
    int T;
    prim();
    //freopen("1.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        memset(vis,-1,sizeof(vis));
        bfs();
        if(vis[a]!=-1)cout<<vis[a]<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
