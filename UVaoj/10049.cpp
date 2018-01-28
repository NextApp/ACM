#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int f[N],sum[N];
int cnt=0;
void init()
{
    cnt=2;
    f[1]=1,f[2]=2;
    sum[1]=1;
    for(int i=2;i<4820;i++)
            for(int j=0;j<f[i];j++)
            {
                sum[cnt]=sum[cnt-1]+i;
                f[cnt++]=i;
            }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)&&n)
    {
        n--;
        printf("%d\n",upper_bound(sum,sum+cnt,n)-sum);
    }
    return 0 ;
}
