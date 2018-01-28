#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5000
using namespace std;
int count(int s,int k)
{
    int sum=0;
    while(s>1)
    {
        sum+=s/k;
        s/=k;
    }
    return sum;
}
int M[N+100],C[1000],cnt;
void prime_list()
{
    cnt=0;
    memset(M,0,sizeof(M));
    for(int i=2;i<N;i++)
    if(!M[i])
    {
        C[cnt++]=i;
        for(int j=i*i;j<=N;j+=i)
        M[j]=i;
    }

}
int big_pow(int n,int k)
{
    int result=0;
    while(n%k==0)
    {
        result++;
        n/=k;
    }
    return result;
}
int main()
{
    int T,id=1,n,k;
    prime_list();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&k,&n);
        int mm=1000000;
        for(int i=0;C[i]<=k&&i<cnt;i++)
        if(k%C[i]==0)
        {
            int s=big_pow(k,C[i]);
            mm=min(mm,count(n,C[i])/s);
        }
        printf("Case %d:\n",id++);
        if(!mm)printf("Impossible to divide\n");
        else printf("%d\n",mm);
    }
    return 0;
}
