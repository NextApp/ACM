#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define INF 120000000
using namespace std;
struct T
{
    double x,y;
}A[1200];
int n;
double M[1200][1200],d[1200];
void prime()
{
    for(int i=1;i<n;i++)
    d[i]=INF;
    d[0]=0;
    int k=0,f=0;
    double sum=0;
    while(k<n-1)
    {
        for(int i=1;i<n;i++)
        if(M[i][f]&&d[i]&&M[i][f]<d[i])
            d[i]=M[i][f];
        double m=INF;
        for(int i=1;i<n;i++)
        if(d[i]&&d[i]<m)
        {
            m=d[i];
            f=i;
        }
        sum+=m;
        d[f]=0;k++;
    }
    printf("%.2lf\n",sum);
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        if(t)cout<<endl;
        cin>>n;
        memset(M,0,sizeof(M));
        for(int i=0;i<n;i++)
            cin>>A[i].x>>A[i].y;
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        M[i][j]=M[j][i]=sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+(A[i].y-A[j].y)*(A[i].y-A[j].y));
        prime();
    }
    return 0;
}
