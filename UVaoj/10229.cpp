#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
long long  mod;
void matrix(long long  a[],long long  b[],long long c[])
{
    long long q=a[0]*b[0]+a[1]*b[2];
    long long w=a[0]*b[1]+a[1]*b[3];
    long long e=a[2]*b[0]+a[3]*b[2];
    long long r=a[2]*b[1]+a[3]*b[3];
    c[0]=q%mod,c[1]=w%mod,c[2]=e%mod,c[3]=r%mod;
}
long long p[]= {1,1,1,0};
void pow_mod(long long a[],int n)
{
    if(n>1)
    {
        pow_mod(a,n/2);
        matrix(a,a,a);
        if(n%2)matrix(a,p,a);
    }
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m>=1)
        {
            mod=pow(2,n);
            long long a[10];
            memcpy(a,p,sizeof(p));
            pow_mod(a,m-1);
            cout<<a[0]<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
