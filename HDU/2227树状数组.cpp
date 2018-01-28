#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define MOD 1000000007
using namespace std;
int sum[maxn],n,num[maxn],data[maxn];
int cmp(const int i,const int j)
{
    if(data[i]!=data[j])return data[i]<data[j];
    else return i<j;
}
int lowbit(int p)
{
    return p&-p;
}
int Sum(int p)
{
    int s=0;
    while(p>=1)
    {
        s=(s+sum[p])%MOD;
        p-=lowbit(p);
    }
    return s;
}
void insert(int p,int v)
{
    while(p<=n)
    {
        sum[p]=(sum[p]+v)%MOD;
        p+=lowbit(p);
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data[i]);
            num[i]=i;
        }
        sort(num,num+n,cmp);
        int result=0;
        for(int i=0;i<n;i++)
        {
            int m=Sum(num[i]);
            insert(num[i]+1,m+1);
            result=(result+m+1)%MOD;
        }
        printf("%d\n",result);
    }
    return 0;
}
