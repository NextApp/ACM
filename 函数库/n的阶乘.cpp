#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100000000
#define M 400
using namespace std;
long long s[M];
int main()
{
    long long n,j;
    while(cin>>n)
    {
        memset(s,0,sizeof(s));
        s[0]=1;
        for(long long i=1;i<=n;i++)
        {
            int k=0;
            for(int k=0;k<M;k++)
            s[k]*=i;
            for(int k=0;k<M;k++)
            if(s[k]>N)s[k+1]+=s[k]/N,s[k]%=N;
        }
        for(j=M;j>=0;j--)if(s[j]>0)break;
        printf("%lld!\n%lld",n,s[j]);
        for(int k=j-1;k>=0;k--)printf("%08lld",s[k]);
        cout<<endl;
    }
    return 0;
}
