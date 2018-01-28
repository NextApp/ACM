#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct T
{
    int a,b,t;
} A[6000];
int d[6000][6000];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->t-b->t)return b->t-a->t;
}
int main()
{
   //freopen("1.txt","r",stdin);
    int n=0;
    while(~scanf("%d%d",&A[n].a,&A[n].b))
    {
        if(A[n].b>=A[n].a)
        {
            A[n].t=A[n].b-A[n].a;
            n++;
        }
    }
    qsort(A,n,sizeof(A[0]),cmp);
    memset(d,-1,sizeof(d));
    d[0][0]=A[0].t;
    int mm=0;
    for(int i=0; i<n; i++)
    for(int j=0; j<=mm; j++)
        {
            int ok=0;
            if(!j)
            {
                ok=1;
                if(i)d[i][j]=max(d[i-1][j],A[i].t);
            }
            else if(i)
            {
                int s=min(d[i-1][j-1]-A[i].a,A[i].t);
                if(d[i-1][j-1]-A[i].a>=0)ok=1;
                d[i][j]=max(s,d[i-1][j]);
            }
            if(ok)mm=max(j+1,mm);
        }
    printf("%d\n",mm);
    return 0;
}
