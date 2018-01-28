#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int pow_mod(int a,int n,int m)
{
    if(n/2<1)return a%m;
    int x=pow_mod(a,n/2,m);
    long long ans=(long long)x*x%m;
    if(n%2==1)ans=ans*a%m;
    return (int)ans;
}
int main()
{
    int a,n,m;
    while(cin>>a>>n>>m)
    {
        cout<<pow_mod(a,n,m)<<endl;
    }
}
