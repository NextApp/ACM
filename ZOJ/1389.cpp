#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 51000
#define fe 0.000001
using namespace std;
struct T
{
    long double b,h,w,d,v;
} A[N];
int n;
long double V,l;
int P(long double s)
{
    long double sum=0;
    for(int i=0; i<n; i++)
        if(s-A[i].b>=0)
        {
            if(s>=A[i].b+A[i].h)sum+=A[i].v;
            else sum+=(s-A[i].b)*A[i].w*A[i].d;
        }
    if(fabs(sum-V)<=fe)return 1;
    else if(sum>V)return 1;
    else return -1;
}
long double b_search()
{
    long double s=0,h=l,k;
    while(s<=h)
    {
        k=(s+h)/2;
        int ok=P(k);
        if(ok>0)h=k-fe;
        else s=k+fe;
    }
    return k;
}
int main()
{
  // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long double sum=0;
        l=0;
        for(int i=0; i<n; i++)
        {
            cin>>A[i].b>>A[i].h>>A[i].w>>A[i].d;
            A[i].v=A[i].h*A[i].w*A[i].d;
            sum+=A[i].v;
            l=max(l,A[i].h+A[i].b);
        }
        cin>>V;
        if(V>sum)cout<<"OVERFLOW"<<endl;
        else
        {
            long double s=b_search();
            printf("%.2llf\n",s);
        }
    }
    return 0;
}
