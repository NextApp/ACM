#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long N[15],vis[15],add[15];
int a[20];
long long count(long long re)
{
    for(int i=0; i<=9; i++)
        if(vis[i]>1)re/=N[vis[i]];
    return re;
}
int main()
{
    long long f=1;
    N[0]=1;
    for(long long i=f; i<=12; i++)
    {
        N[i]=i*f;
        f=i*f;
    }
    int n=0;
    while(~scanf("%d",&n)&&n)
    {
        memset(vis,0,sizeof(vis));
        memset(add,0,sizeof(add));
        long long sum=0,re;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        re=count(N[n]);
        for(int i=0; i<n; i++)
        {
            int t=a[i];
            if(!add[t])
            {
                add[t]=re*vis[t]/n;
              //  vis[t]--;
               // add[t]=count(N[n-1]);
                sum+=add[t]*t;
               // vis[t]++;
            }
        }
        long long u=0;
        int i;
        for(i=0; i<n||u; i++)
        {
            if(i<n)a[i]=(u+sum)%10;
            else a[i]=u%10;
            if(i<n)u=(u+sum)/10;
            else u=u/10;
        }
        int ok=0;
        for(int j=i-1; j>=0; j--)
        {
            if(!j||a[j]!=0)ok=1;
            if(ok)printf("%d",a[j]);
        }
        printf("\n");
    }
    return 0;
}
