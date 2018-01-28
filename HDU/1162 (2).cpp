#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define N 120
using namespace std;
int n,d[N*N],e,p[N],u[N*N],v[N*N];
double M[N*N],a[N],b[N];
int cmp(const int a,const  int b)
{
    return M[a]<M[b];
}
int find(int i)
{
    return p[i]!=i?p[i]=find(p[i]):i;
}
void kruscal()
{
    for(int i=0; i<n; i++)p[i]=i;
    for(int j=0; j<e; j++)d[j]=j;
    sort(d,d+e,cmp);
    double sum=0;
    int k=0,x,y,t;
    for(int i=0; i<e; i++)
    {
        t=d[i];
        x=find(u[t]);
        y=find(v[t]);
        if(x!=y)
        {
            sum=sum+M[t];
            p[y]=x;
        }
    }
    printf("%.2lf\n",sum);
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            cin>>a[i]>>b[i];
        e=0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                u[e]=i,v[e]=j;
                M[e++]=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
            }
        kruscal();
    }
    return 0;
}
