#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double M[12000],c[120],r[120];
int cc[12000],rr[12000],n,t,d[12000],p[120];
int cmp(const int a,const int b)
{
    return M[a]<M[b];
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
void kruskal()
{
    for(int i=0; i<n; i++)p[i]=i;
    for(int i=0; i<t; i++)d[i]=i;
    sort(d,d+t,cmp);
    double ans=0;
    for(int i=0; i<t; i++)
    {
        int e=d[i];
        int x=find(cc[e]),y=find(rr[e]);
        if(x!=y)
        {
            ans+=M[e];
            p[x]=y;
        }
    }
    printf("%.2lf\n",ans);
}
int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        if(i)cout<<endl;
        cin>>n;
        t=0;
        for(int j=0; j<n; j++)
            cin>>c[j]>>r[j];
        for(int j=0; j<n-1; j++)
            for(int k=j+1; k<n; k++)
                {
                    cc[t]=j,rr[t]=k;
                    M[t++]=sqrt((c[j]-c[k])*(c[j]-c[k])+(r[j]-r[k])*(r[j]-r[k]));
                }
        kruskal();
    }
    return 0;
}
