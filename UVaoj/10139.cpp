#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int prime[52000];
int m,n;
int M[102000],num;
void prime_make()
{
    num=0;
    memset(M,0,sizeof(M));
    for(int i=2; i<=100000; i++)
        if(!M[i])
        {
            prime[num++]=i;
            for(int j=i+i; j<=100000; j+=i)
                M[j]=i;
        }
}
int div_num(int a)
{
    int sum=0,s=n;
    while(s>=a)
    {
        sum+=s/a;
        s/=a;
    }
    return sum;
}
int First[120],Second[120];
int main()
{
    prime_make();
    while(~scanf("%d%d",&n,&m))
    {
        int l=0,t=m;
        if(n<=m)
        {
            for(int i=0; i<num&&prime[i]<=m; i++)
            {
                if(m%prime[i]==0)
                {
                    int s=0;
                    while(m%prime[i]==0)
                    {
                        s++;
                        m/=prime[i];
                    }
                    Second[l]=prime[i];
                    First[l++]=s;
                }
            }
            if(m>1)
            {
                Second[l]=m;
                First[l++]=1;
            }
        }
        int OK=1;
        for(int i=0; i<l; i++)
        {
            int s=div_num(Second[i]);
            if(s<First[i])
            {
                OK=0;
            }
        }
        if(OK)
        {
            printf("%d divides %d!\n",t,n);
        }
        else
        {
            printf("%d does not divide %d!\n",t,n);
        }

    }
    return 0;
}
