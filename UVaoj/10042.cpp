#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 33000
bool M[maxn+10]={false};
int prime[maxn+10],num;
int prime_make()
{
    num=0;
    for(int i=2;i<maxn;i++)
    {
        if(!M[i])prime[num++]=i;
        for(int j=0;j<num&&i*prime[j]<maxn;j++)
        {
            M[i*prime[j]]=true;
            if(0==i%prime[j])break;
        }
    }
}
int cal(int n)
{
    int s=0;
    while(n/10)
    {
        s+=n%10;
        n/=10;
    }
    return s+n;
}
int main()
{
    prime_make();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d",&m);
        m++;
        while(1)
        {
            int s=m,all=0,result=cal(m);
            for(int i=0;i<num&&prime[i]<s;i++)
            if(s%prime[i]==0){
                int sum=0;
                while(s%prime[i]==0)
                {
                    sum++;
                    s/=prime[i];
                }
                all+=cal(prime[i])*sum;
            }
            if(s>1)
            {
                all+=cal(s);
            }
            if(s!=m&&all==result)break;
            m++;
        }
        printf("%d\n",m);
    }
    return 0;
}
