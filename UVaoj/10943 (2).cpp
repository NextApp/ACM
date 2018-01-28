#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[120][120];
void dp()
{
    memset(d,0,sizeof(d));
    for(int k=0; k<=100; k++)d[k][1]=1;
    for(int n=0; n<=100; n++)
        for(int k=2; k<=100; k++)
            for(int s=0; s<=n; s++)
            {
                d[n][k]+=d[s][k-1];
                d[n][k]%=1000000;
            }
}
int main()
{
    dp();
    int n,k;
    while(~scanf("%d%d",&n,&k)&&n+k)
    {
        printf("%d\n",d[n][k]);
    }
    return 0;
}
