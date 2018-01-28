#include<iostream>
#include<cstring>
#include<cstdio>
#define ULL unsigned long long
using namespace std;
int mod;
void Matrix(ULL &a,ULL &b,ULL &d,ULL n)
{
    if(n<=1){
     a=1,b=1,d=0;
        return ;
    }
    Matrix(a,b,d,n/2);
    ULL aa,bb,dd;
    aa=a*a+b*b;
    bb=a*b+b*d;
    dd=b*b+d*d;
    if(n%2)
    {
        a=(aa+bb)%mod;
        b=aa%mod;
        d=bb%mod;
    }
    else
    {
        a=aa%mod;
        b=bb%mod;
        d=dd%mod;
    }
}
int main()
{
    ULL a,b,c,n;
    a=1;
    int id=1;
    while(~scanf("%lld%d",&n,&mod))
    {
        if(!n&&!mod)return 0;
        Matrix(a,b,c,n);
        ULL s=(2*a-1+mod)%mod;
        printf("Case %d: %lld %d %lld\n",id++,n,mod,s);
    }
    return 0;
}
