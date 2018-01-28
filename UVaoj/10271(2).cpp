#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[5050][1050],a[5050],n,k;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&k,&n);
        for(int i=n; i; i--)
            scanf("%d",&a[i]);
        d[0][0]=0;
        for(int i=1; i<=n; i++)
            for(int j=1; 3*j<=i&&j<=8+k; j++)
            {
                d[i][j]=d[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);
                if(3*j<i)d[i][j]=min(d[i-1][j],d[i][j]);
            }
        printf("%d\n",d[n][k+8]);
    }
    return 0;
}
