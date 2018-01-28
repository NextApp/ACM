#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5700
using namespace std;
int d[N];
struct E
{
    int a,b;
} A[N];
bool cmp(E aa,E bb)
{
    return aa.b>bb.b;
}
int main()
{
    int n=0;
    while(~scanf("%d%d",&A[n].a,&A[n].b))
    {
        if(A[n].b>=A[n].a)A[n].b-=A[n++].a;
    }
    sort(A,A+n,cmp);
    memset(d,-1,sizeof(d));
    int mm=0;
    for(int i=0; i<n; i++)
    {
        int ok=0;
        for(int j=mm; j>=0; j--)
        {
            int s=A[i].b,o=0;
            if(j&&d[j-1]>=A[i].a)
            {
                o=1;
                if(j==mm)ok=1;
                s=min(d[j-1]-A[i].a,s);
            }
            if(!i||o)d[j]=max(s,d[j]);
        }
        if(ok||!i)mm++;
    }
    printf("%d\n",mm);
    return 0;
}
