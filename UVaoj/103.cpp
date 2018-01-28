#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100
#define INF 100000000
using namespace std;
int wx,wy,A[N][N],G[N][N],d[N];
int compare(int i,int j)
{
    int okk=1,ok=1;
    for(int t=0; t<wy; t++)
    {
        if(A[i][t]<=A[j][t])okk=0;
        if(A[i][t]>=A[j][t])ok=0;
    }
    if(okk)return -1;
    if(ok)return 1;
    return 0;
}
int dp(int cur)
{
    if(d[cur]>=0)return d[cur];
    int t=0;
    for(int i=0; i<wx; i++)
        if(G[cur][i])t=max(t,dp(i)+1);
    return d[cur]=t;
}
void print_out(int cur)
{
    if(d[cur]>0)cout<<cur+1<<' ';
    else cout<<cur+1<<endl;
    for(int i=0; i<wx; i++)
        if(G[cur][i]&&d[cur]==d[i]+1)
        {
            print_out(i);
            break;
        }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>wx>>wy)
    {
        for(int i=0; i<wx; i++)
        {
            for(int j=0; j<wy; j++)
                cin>>A[i][j];
            sort(A[i],A[i]+wy);
        }
        memset(G,0,sizeof(G));
        for(int i=0; i<wx-1; i++)
            for(int j=i+1; j<wx; j++)
            {
                int t=compare(i,j);
                if(t==1)G[i][j]=1;
                else if(t==-1)G[j][i]=1;
            }
        for(int i=0; i<wx; i++)d[i]=-INF;
        int maxx=0,t=0;
        for(int i=0; i<wx; i++)
            if(d[i]==-INF)
            {
                int s=dp(i);
                if(maxx<s)
                {
                    maxx=s;
                    t=i;
                }
            }
        cout<<maxx+1<<endl;
        print_out(t);
    }
    return 0;
}
