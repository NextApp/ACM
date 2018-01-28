#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct T
{
    int a,b,c;
} A[100];
int G[100][100],d[100],n;
int dp(int cur)
{
    int &ans=d[cur];
    if(ans>0)return ans;
    int t=0;
    for(int i=0; i<n; i++)
        if(G[cur][i])t=max(t,dp(i)+A[i].c);
    return ans=t;
}
int main()
{
    freopen("1.txt","r",stdin);
    int id=1;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            for(int i=0; i<n; i++)
            {
                cin>>A[i].a>>A[i].b>>A[i].c;
                A[i+n].a=A[i].b,A[i+n].b=A[i].c,A[i+n].c=A[i].a;
                A[i+n+n].a=A[i].c,A[i+n+n].b=A[i].a,A[i+n+n].c=A[i].b;
            }
            memset(G,0,sizeof(G));
            memset(d,-1,sizeof(d));
            n*=3;
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if((A[i].a<A[j].a&&A[i].b<A[j].b)||(A[i].a<A[j].b&&A[i].b<A[j].a))
                        G[i][j]=1;
            int m=0;
            for(int i=0; i<n; i++)
                if(d[i]<0)
                    m=max(m,dp(i)+A[i].c);
            cout<<"Case "<<id++<<": maximum height = "<<m<<endl;
        }
    }
    return 0;
}
