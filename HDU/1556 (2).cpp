#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100008],n;
int Lowbit(int x)
{
    return x&(-x);
}
int Sum(int s)
{
    int sum=0;
    while(s)
    {
        sum+=a[s];
        s-=Lowbit(s);
    }
    return sum;
}
int Update(int s,int num)
{
    while(s<=n)
    {
        a[s]+=num;
        s+=Lowbit(s);
    }
}
int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        int x,y;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            Update(x,1);
            Update(y+1,-1);
        }
        printf("%d",a[1]);
        for(int i=2;i<=n;i++)
            printf(" %d",Sum(i));
        printf("\n");
    }
    return 0;
}
