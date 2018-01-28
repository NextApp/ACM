#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 33000
using namespace std;
struct T
{
    int x,y;
} M[N];
int n,a[N],ss[N];
int Lowbit(int x)
{
    return x&(-x);
}
int Sum(int i)
{
    int sum=0;
    while(i)
    {
        sum+=a[i];
        i-=Lowbit(i);
    }
    return sum;
}
int Update(int i,int x)
{
    while(i<=32001)
    {
        a[i]+=x;
        i+=Lowbit(i);
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        memset(ss,0,sizeof(ss));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&M[i].x,&M[i].y);
            ss[Sum(M[i].x+1)]++;
            Update(M[i].x+1,1);
        }
        for(int i=0; i<n; i++)
            printf("%d\n",ss[i]);
    }
    return 0;
}
