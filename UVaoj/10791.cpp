#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int prime_num,prime[7000];
bool M[70000]={false,};
void  prime_list()
{
    prime_num=0;
    for(int i=2;i<65536;i++)
    if(!M[i]){
        prime[prime_num++]=i;
        for(int j=i;j<65536;j+=i)
        M[j]=true;
    }
}
int main()
{
    prime_list();
    int n,p[15],nu[15],id=1;
    long long a=1;
    while(~scanf("%d",&n)&&n)
    {
        int s=n,cnt=0;
        memset(nu,0,sizeof(nu));
        for(int i=0;(long long)prime[i]*prime[i]<=s;i++)
        if(s%prime[i]==0){
            while(s%prime[i]==0)
            {
                nu[cnt]++;
                s/=prime[i];
            }
            p[cnt++]=prime[i];
        }
        if(s>1)
        {
            nu[cnt]++;
            p[cnt++]=s;
        }
        printf("Case %d: ",id++);
        if(cnt==1||n==1)
        {
            long long s=n;
            printf("%lld\n",s+1);
        }
        else
        {
            int sum=0;
            for(int i=0;i<cnt;i++)
            sum+=pow(p[i],nu[i]);
            printf("%d\n",sum);
        }
    }
    return 0;
}
