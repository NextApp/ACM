#include<iostream>
#include<cstdio>
#define N 1000000007
using namespace std;
int Pow(int n)
{
    if(!n)return 1;
    long long s=Pow(n/2);
    if(n%2)return s*s*2%N;
    else return s*s%N;
}
int main()
{
    int n,id=1,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",id++,(int)((long long)n*Pow(n-1)%N));
    }
    return 0;
}
