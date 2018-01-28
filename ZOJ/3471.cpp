#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int bin[]={1,2,4,8,16,32,64,128,256,512,1024};
int n,d[2000],a[30][30];
int dp(int m)
{
    if(d[m])return d[m];
    int sum=0;
    for(int i=0;i<n;i++)
    if(m&bin[i])
    {
        for(int j=0;j<n;j++)
        if(i!=j&&m&bin[j])sum=max(sum,dp(m-bin[j])+a[i][j]);
    }
    return d[m]=sum;
}
int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        memset(d,0,sizeof(d));
        dp((1<<n)-1);
        printf("%d\n",d[(1<<n)-1]);
    }
    return 0;
}
