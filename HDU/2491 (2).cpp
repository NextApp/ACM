#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 101000
using namespace std;
int n,a[N],b[N],c[N],p[N],d[N];
int cmp(const int i,const int j)
{
    return c[i]>c[j];
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            if((a[i]+b[i])%2==0)c[i]=((long long)(a[i])+b[i])/2+1;
            else c[i]=((long long)(a[i])+b[i]+1)/2;
            p[i]=i,d[i]=(b[i]-a[i])/2+1;
        }
        sort(p,p+n);
        int first=c[p[0]],ok=1;
        for(int i=1;i<n&&ok;i++)
        {
            int w=p[i];
            first=max(a[w],first);
            if(first+d[w]<=b[w])first+=d[w];
            else ok=0;
        }
        if(ok)printf("YES");
        else printf("NO");
        printf("\n");
    }
    return 0;
}
