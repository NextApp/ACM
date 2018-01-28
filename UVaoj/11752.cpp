#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 18446744073709551615
using namespace std;
unsigned long long m[120000];
int M[100],prime[100],num;
void prime_list()
{
    num=0;
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=80; i++)
        if(!prime[i])
        {
            for(int j=i+i; j<=80; j+=i)
                prime[j]=1;
        }
        else M[num++]=i;
}
int judge(unsigned long long L,unsigned long long nu)
{
    int s=0;
    unsigned long long N=INF;
    while(N/L)
    {
        s++;
        N/=L;
    }
    if(s>=nu)return 1;
    return 0;
}
int main()
{
   // freopen("12.txt","w",stdout);
    prime_list();
    m[0]=1;
    int sum=0;
    cout<<1<<endl;
    for(int i=2; i<(1<<16); i++)
    {
        for(int j=0;M[j]<64;j++)
        if(judge(i,M[j]))
        {
            unsigned long long l=1,t=i;
            for(int k=0;k<M[j];k++)
            l*=t;
            if(l<=0)break;
            m[sum++]=l;
        }
        else break;
    }
    sort(m,m+sum);
    for(int i=0;i<sum-1;i++)
    if(m[i]!=m[i+1])cout<<m[i]<<endl;
    cout<<m[sum-1]<<endl;
    return 0;
}
