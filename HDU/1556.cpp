#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100200];
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        memset(a,0,sizeof(a));
        int x,y;
        for(int i=0;i<n;++i)
            {
                scanf("%d%d",&x,&y);
                ++a[x],--a[y+1];
            }
        int sum=a[1];
        printf("%d",sum);
        for(int i=2;i<=n;++i)
        {
            sum+=a[i];
            printf(" %d",sum);
        }
        printf("\n");
    }
    return 0;
}
