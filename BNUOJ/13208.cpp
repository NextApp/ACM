#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
#define MAX 100001001
#define X 4294967296
using namespace std;
bitset<50001000>p(1);//bitset占用内存小，为一位
int prime[5765155];
unsigned int S[5765155];//unsigned int范围是0-2^32-1
int primenum;
int creatprime2(int lim) //二倍压缩求素数
{
    int sievelimit = (sqrt(lim * 1.0) - 1 )/ 2;
    int maxindex = ( lim - 1 ) / 2;
    int n,t,k;
    for(n = 1; n <= sievelimit; n++)
    {
        if(p.test(n)==0)
        {
            t = 2*n + 1;
            for(k = 2*n*(n+1); k <= maxindex; k += t)
                p.set(k);
        }
    }
    prime[0] = 2;
    S[0]=2;
    primenum = 1;
    for(n = 1; n <= maxindex ; n++)
    {
        if(p.test(n)==0)
        {
            unsigned long long s=((unsigned long long)S[primenum-1]*(2*n+1))%X;
            S[primenum]=(unsigned int)s;//打间隔表，类似求和的Sn。
            prime[primenum++] = 2*n+1;
        }
    }
}
int m;
long long Pow(long long a,int n)
{
    long long s=1;
    for(int i=1;i<=n;i++)
    s*=a;
    return s;
}
long long M(int k)//求每个质因子的幂
{
    for(int i=1;i<=30;i++)
    {
        long long a=Pow(prime[k],i);
        if(a>m)return i-1;
    }
}
int B_search(int r,int first,int last)//二分求间隔值,类似：5554433222111111
{
    int k;
    while(first<=last)
    {
        k=first+(last-first)/2;
        int n1=M(k),n2=M(k+1);
        if(n1==r&&n2<r)return k;
        else if(n2>=r)first=k+1;
        else if(n1<r)last=k-1;
        else return -1;
    }
    return -1;
}
int main()
{
    int T,id=1;
    creatprime2(MAX);
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>m;
        unsigned long long s=1;
        int last=lower_bound(prime,prime+primenum,m)-prime;
        int fa=M(0),first=0;
        while(fa>1)
        {
            int k=B_search(fa,first,last);
            if(k!=-1)s=(s*(unsigned long long)S[k])%X,first=k+1;
            else s=(s*(unsigned long long)S[first-1])%X;
            fa--;
        }
        if(prime[last]>m)last--;
        s=(s*(unsigned long long)S[last])%X;
        cout<<"Case "<<id++<<": "<<s<<endl;
    }
    return 0;
}
