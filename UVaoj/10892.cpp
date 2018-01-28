#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int prime[4500],prime_num,a[2000];
int main()
{
    int n,num;
    while(~scanf("%d",&n)&&n)
    {
        num=0;
        int s=n,sum=0;
        if(s!=1)sum=1;
        int i;
        for(i=2;i*i<s;i++)
        if(s%i==0)a[num++]=i,a[num++]=s/i;
        if(i*i==s)a[num++]=i;
        for(int i=0; i<num; i++)
        {
            for(int j=i+1; j<num; j++)
                if((long long)a[i]*a[j]/gcd(a[i],a[j])==n)
                    sum++;
             sum++;
        }
        sum++;
        printf("%d %d\n",n,sum);
    }
    return 0;
}
