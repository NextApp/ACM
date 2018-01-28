#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n;
struct T
{
    int a,b;
} A[110000];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->b-b->b)return b->b-a->b;
    else return b->a-a->a;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d%d",&A[i].a,&A[i].b);
        qsort(A,n,sizeof(A[0]),cmp);
        int sum=A[0].a+A[0].b,f=A[0].b;
        for(int i=1; i<n; i++)
        {
            if(f>=A[i].a+A[i].b)f-=A[i].a;
            else
            {
                sum+=A[i].a+A[i].b-f;
                f=A[i].b;
            }
        }
        printf("Case %d: %d\n",id++,sum);
    }
    return 0;
}
