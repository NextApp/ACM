#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1002000],b[1002000],c[1002000];
int main()
{
    int T,id=0,M;
    scanf("%d",&T);
    while(T--)
    {
        if(id)printf("\n");
        id=1;
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        scanf("%d%d",&a[i],&b[i]);
        int g=0,s;
        for(int i=M-1;i>=0;i--)
        {
            s=a[i]+b[i]+g;
            c[i]=s%10;
            g=s>9?1:0;
        }
        for(int i=0;i<M;i++)
        printf("%d",c[i]);
        printf("\n");
    }
    return 0;
}
