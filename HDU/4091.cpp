#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
long long  n,V,v1,s1,v2,s2;
int main()
{
    //freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        cin>>V>>v1>>s1>>v2>>s2;
        long long sum=0;
        long long l=0;
        if((long double)s2/v2>(long double)s1/v1)
        {
            long long temp=v1;
            v1=v2;
            v2=temp;
            temp=s1;
            s1=s2;
            s2=temp;
        }
        sum=(V/v1)*s1+((V%v1)/v2)*s2;
        long long sum1,sum2;
        for(long long i=1;i<100000;i++)
        {
            sum1=(V/v1-i)*s1;
            if(sum1<0)break;
            sum2=((v1*i+V%v1)/v2)*s2;
            if(sum1+sum2>sum)sum=sum1+sum2;
        }
        cout<<"Case #"<<id++<<": "<<sum<<endl;
    }
    return 0;
}
