#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1200000
using namespace std;
double w[N];
struct T
{
    double x,y;
} M[1100];
int n,t,u[N],v[N],c[N],p[1100];
int cmp(const int i,const int j)
{
    return w[i]<w[j];
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
void kruskal()
{
    for(int i=0; i<n; i++)p[i]=i;
    for(int i=0; i<t; i++)c[i]=i;
    sort(c,c+t,cmp);
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        int a=find(x-1);
        int b=find(y-1);
        if(a!=b)p[a]=b;
    }
    double sum=0;
    for(int i=0; i<t; i++)
    {
        int e=c[i];
        int x=find(u[e]);
        int y=find(v[e]);
        if(x!=y)
        {
            sum+=w[e];
            p[x]=y;
        }
    }
    printf("%.2f\n",sum);
}
int main()
{
     //freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            cin>>M[i].x>>M[i].y;
        t=0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                u[t]=i;
                v[t]=j;
                w[t]=sqrt((M[i].x-M[j].x)*(M[i].x-M[j].x)+(M[i].y-M[j].y)*(M[i].y-M[j].y));
                t++;
            }
        kruskal();
    }
    return 0;
}
