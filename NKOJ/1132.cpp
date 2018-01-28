#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 1000200
using namespace std;
int d[30000],n;
int A[20200],B[20200];
struct T
{
    int a,b;
}M[20];
int main()
{
  // freopen("1.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&M[i].a,&M[i].b);
        int w,cnt=0;
        scanf("%d",&w);
        for(int i=0;i<n;i++)
            {
                int s=M[i].b,t=1;
                while(s>=t)
                {
                    A[cnt]=t*M[i].a,B[cnt++]=t;
                    s-=t;
                    t*=2;
                }
                if(s)A[cnt]=s*M[i].a,B[cnt++]=s;
            }
        memset(d,0,sizeof(d));
        for(int i=0;i<=w;i++)d[i]=INF;
        d[0]=0;
        for(int i=0;i<cnt;i++)
        for(int j=w;j>=0;j--)
        if(j>=A[i])d[j]=min(d[j],d[j-A[i]]+B[i]);
        printf("%d\n",d[w]!=INF?d[w]:-1);
    }
    return 0;
}
