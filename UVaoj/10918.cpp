#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long long a[40];
    int n;
    a[0]=1;
    a[1]=3;
    for(n=2;n<=30;n++)
    {
        a[n]=a[n-1]*3;
        for(int i=n-2;i>=0;i--)
        a[n]+=a[i]*2;
    }
    while(cin>>n)
    {
        if(n<0)break;
        else if(n%2)cout<<0<<endl;
        else cout<<a[n/2]<<endl;
    }
    return 0;
}
