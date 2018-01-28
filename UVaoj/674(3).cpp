#include<cstdio>
#include<cstring>
#define N 7489
int d[7500];
int a[]= {50,25,10,5,1};
int main()
{
    int n;
    memset(d,0,sizeof(d));
        d[0]=1;
        for(int j=0; j<5; j++)
            for(int i=0; i<=N; i++)
                if(i-a[j]>=0)d[i]+=d[i-a[j]];
    while(scanf("%d",&n)!=EOF)printf("%d\n",d[n]);
    return 0;
}
