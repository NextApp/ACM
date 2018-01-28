#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long R(long long n)
{
    if(n<=0)return 0;
    long long sum=0,p=10;
    while(n)
    {
        sum+=45*(n/p)+(n%p)*(n%p+1)/2;
        n/=10;
    }
    return sum;
}
int main()
{
    //freopen("1.txt","r",stdin);
    long long a,b;
    while(cin>>a>>b)
    {
        if(a<0&&b<0)break;
        else
        {
            cout<<R(b)-R(a-1)<<endl;
        }
    }
    return 0;
}
