#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int M,N,num,fnum[200],T[200];
int ext_gcd(int a,int b,int &x,int &y)
{
      if(b==0)
      {
            x=1;
            y=0;
            return a;
      }else
      {
            int d,x0,y0;
            d=ext_gcd(b,a%b,x0,y0);
            x=y0;
            y=x0-(a/b)*y0;
            return d;
      }
}
void init()
{
    int n=M;
    num=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            T[num++]=i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)T[num++]=n;
}
void mul(int &res,int t)
{
    for(int i=0;i<num;i++)
    while(t%T[i]==0)fnum[i]++,t/=T[i];
    if(t!=1)res=(long long)res*t%M;
}
void chu(int &res,int t)
{
    for(int i=0;i<num;i++)
    while(t%T[i]==0)fnum[i]--,t/=T[i];
    if(t!=1)
    {
        int x,y;
        ext_gcd(t,M,x,y);
        x=(x%M+M)%M;
        res=((long long )res*x)%M;
    }
}
int work()
{
    memset(fnum,0,sizeof(fnum));
    int sum=1,res=1;
    for(int i=2;i<=N;i++)
    {
        int t=4*i-2;
        mul(res,t);
        t=i+1;
        chu(res,t);
        long long fin=res;
        for(int j=0;j<num;j++)
        for(int k=0;k<fnum[j];k++)
        fin=(fin*T[j])%M;
        sum=(sum+fin)%M;
    }
    return sum;
}
int main()
{
    while(scanf("%d%d",&N,&M)==2&&M+N)
    {
        init();
        if(M==1)printf("0");
        else printf("%d\n",work());
    }
    return 0;
}
