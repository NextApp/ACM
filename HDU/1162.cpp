#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define N 120
#define INF 100000000
using namespace std;
double a[N],b[N],M[N][N],v[N];
int n;
double distant(int i,int j)
{
    return sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
}
void prime()
{
    for(int i=1;i<n;i++)v[i]=INF;
    v[0]=0;
    int f=0,j=n-1;
    double mine,sum=0;
    while(j--)
    {
        for(int i=1;i<n;i++)
        if(M[i][f]&&v[i]>M[i][f])
        v[i]=M[i][f];
        mine=INF;
        for(int i=1;i<n;i++)
        if(v[i]&&mine>v[i])
        {
            mine=v[i];
            f=i;
        }
        v[f]=0;
        sum+=mine;
    }
    printf("%.2lf\n",sum);
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
        memset(M,0,sizeof(M));
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        M[i][j]=M[j][i]=distant(i,j);
        prime();
    }
    return 0;
}
