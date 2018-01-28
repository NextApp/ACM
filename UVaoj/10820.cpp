#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
int prime[200],k=0,sum[50200];
int prime_table()
{
    int M[250];
    memset(M,0,sizeof(M));
    for(int i=2; i<125; i++)
        for(int j=i+i; j<250; j+=i)
            M[j]=1;
    for(int i=2; i<250; i++)
        if(!M[i])prime[k++]=i;
}
int factor(int n)
{
    double l=n;
    int d=n;
    for(int i=0; prime[i]<=n&&i<k; i++)
    {
        if(!(n%prime[i]))
        {
            l*=(1-1.0/prime[i]);
            while(!(n%prime[i]))n/=prime[i];
        }
    }
    if(n!=1)l*=(1-1.0/n);
    sum[d]=sum[d-1]+(int)l*2;
}
int main()
{
    prime_table();
    sum[1]=1;
    for(int i=2; i<50001; i++)
        factor(i);
    int n;
    while(cin>>n)
    {
        if(!n)return 0;
        else
            cout<<sum[n]<<endl;
    }
    return 0;
}
