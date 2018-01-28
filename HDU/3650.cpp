#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n;
struct T
{
    int a,b;
}A[120];
int cmp(const void *_a,const void*_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->a-b->a)return a->a - b->a;
    else return a->b - b->b;
}
int main()
{
  //  freopen("1.txt","r",stdin);
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)
        scanf("%d%d",&A[i].a,&A[i].b);
        qsort(A,n,sizeof(A[0]),cmp);
        int m=n,sn=0;
        int vis[120];
        memset(vis,0,sizeof(vis));
        while(m)
        {
            int s=-1;
            for(int i=0;i<n;i++)
            {
                if(!vis[i]&&s<A[i].a)
                {
                    s=A[i].b;
                    m--;
                    vis[i]=1;
                }
            }
            sn++;
        }
        printf("%d\n",sn);
    }
    return 0;
}
