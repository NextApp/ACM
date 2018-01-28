#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 100000000
#define N 20
using namespace std;
int n,m,A[N],nodew[N],M[N][N],d[N],OK,result[N];
double r;
int cmp(int a[],int b[])
{
    for(int i=0; i<m; i++)
        if(a[i]<b[i])return 1;
    return 0;
}
void prime()
{
    for(int i=1; i<m; i++)
        d[i]=INF;
    d[0]=0;
    int t=1,f=0,mm=0;
    while(t<m)
    {
        for(int i=1; i<m; i++)
            if(i!=f&&M[A[i]][A[f]]<d[i])
                d[i]=M[A[i]][A[f]];
        int mine=INF;
        for(int i=1; i<m; i++)
            if(d[i]&&mine>d[i])
            {
                mine=d[i];
                f=i;
            }
        d[f]=0;
        mm+=mine;
        t++;
    }
    int w=0;
    for(int i=0; i<m; i++)
        w+=nodew[A[i]];
    if(!OK)
    {
        for(int i=0; i<m; i++)
            result[i]=A[i];
        r=(double)mm/w;
    }
    else
    {
        double r1=(double)mm/w;
        if(r1<r||(r1==r&&cmp(A,result)))
        {
            for(int i=0; i<m; i++)
                result[i]=A[i];
            r=r1;
        }
    }
    OK=1;
}
void print_subet(int cur)
{
    if(cur==m)
    {
        prime();
        return ;
    }
    int s=cur?A[cur-1]+1:0;
    for(int i=s; i<n; i++)
    {
        A[cur]=i;
        print_subet(cur+1);
    }
}
int main()
{
 //   freopen("1.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m)return 0;
        for(int i=0; i<n; i++)
            scanf("%d",&nodew[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&M[i][j]);
        r=INF;
        OK=0;
        print_subet(0);
        for(int i=0; i<m-1; i++)
            printf("%d ",result[i]+1);
        printf("%d\n",result[m-1]+1);
    }
    return 0;
}
