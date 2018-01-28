#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long sum[50];
int main()
{
    sum[1]=sum[2]=1;
    for(long long i=3;i<41;i++)
    sum[i]=sum[i-1]+sum[i-2];
    int n;
    while(cin>>n)
    {
        long long s=0;
        for(int i=1;i<=n;i++)
        s+=sum[i];
        cout<<s<<endl;
    }
    return 0;
}
