#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 10200
#define E 0.0000001
using namespace std;
double a[N],b[N],c[N];
int n;
double P(double x)
{
    double mm=a[0]*x*x+b[0]*x+c[0];
    for(int i=1; i<n; i++)
        mm=max(a[i]*x*x+b[i]*x+c[i],mm);
    return mm;
}
double b_search()
{
    double f=0,e=1000,k,s;
    while(f<=e)
    {
        k=(f+e)/2.0;
        double kk=k+E,ss=k-E;
        s=P(k);
        double o=P(kk),d=P(ss);
        if(s<=o&&s<=d)return s;
        else if(o<=s)k=f=k+E;
        else k=e=k-E;
    }
    return P(k);
}
int main()
{
    freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
        printf("%.4lf\n",b_search());
    }
    return 0;
}
