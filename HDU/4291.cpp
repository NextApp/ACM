#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000000007
#define M 222222224
#define L 183120
#define LL long long
using namespace std;
void juzhen_mul(LL &a,LL &b,LL &c,LL &d,LL n,LL mod)
{
    if(n==-1) a=0;
    else if(n==0)a=1;
    else if(n==1)a=3,b=1,c=1,d=0;
    else
    {
        juzhen_mul(a,b,c,d,n/2,mod);
        LL A=(a*a+b*c)%mod,B=(b*a+b*d)%mod,C=(a*c+d*c)%mod,D=(b*c+d*d)%mod;
        a=A,b=B,c=C,d=D;
        if(n%2)A=(3*a+b)%mod,B=a,C=(3*c+d)%mod,D=c;
        a=A,b=B,c=C,d=D;
    }
}
int main()
{
    LL n;
    while(~scanf("%I64d",&n))
    {
          LL a,b,c,d;
          juzhen_mul(a,b,c,d,n-1,L);
          juzhen_mul(a,b,c,d,a-1,M);
          juzhen_mul(a,b,c,d,a-1,N);
          printf("%I64d\n",a);
    }
    return 0;
}
