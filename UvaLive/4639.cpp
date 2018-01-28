#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 240
#define eps 1e-8
using namespace std;
int m,n,OK;
struct T
{
    int x,y,color;
} A[N],B[N];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->x-b->x)return a->x-b->x;
    else return a->y-b->y;
}
int pan_xian()
{
    if(B[0].color)
    {
        for(int i=0; i<n; i++)
            if(!B[i].color)return 0;
    }
    else
    {
        for(int j=n; j<n+m; j++)
            if(B[j].color)return 0;
    }
    return 1;
}
int check(int x,double k,double bb,int ok)
{
    int b1,b2,b3,w1,w2,w3;
    b1=b2=b3=w1=w2=w3=0;
    double l;
    for(int t=0; t<n+m; t++)
    {
        if(ok)l=bb-A[t].y+A[t].x*k;
        else l=A[t].x-x;
        int ok=A[t].color;
        if(l>eps)ok?++b1:++w1;
        else if(l<eps&&l>-eps)ok?++b2:++w2;
        else ok?++b3:++w3;
    }
    if(!b1&&!b3&&!w3&&!w1)return pan_xian();
    if(b2&&w2)return 0;
    if(b1&&b3||w1&&w3)return 0;
    if(b1&&w1||b3&&w3)return 0;
    return 1;
}
void judge(int t,int num)
{
    for(int i=t; i<n+num&&!OK; i++)
        for(int j=i+1; j<n+num&&!OK; j++)
        {
            if(A[i].x!=A[j].x)
            {
                double k=(double)(A[j].y-A[i].y)/(A[j].x-A[i].x);
                if(check(0,k,A[i].y-k*A[i].x,1))OK=1;
            }
            else if(check(A[i].x,0,0,0))OK=1;
        }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!m&&!n)return 0;
        OK=0;
        for(int i=0; i<n+m; i++)
        {
            scanf("%d%d",&A[i].x,&A[i].y);
            A[i].color=i<n?1:0;
        }
        memcpy(B,A,sizeof(A));
        qsort(B,n+m,sizeof(B[0]),cmp);
        judge(0,0);
        judge(n,m);
        if(n<=1&&m<=1)OK=1;
        if(OK)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
