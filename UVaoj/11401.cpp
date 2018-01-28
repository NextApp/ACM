#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long n;
    while(~scanf("%lld",&n))
    {
        if(n<3)break;
        long long x=n/2-1,a=(n+1)/2;
        printf("%lld\n",(n-x-2)*(x+1)*x/2+a*(a-1)*(a-2)/6);
    }
    return 0;
}
