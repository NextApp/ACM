#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long d[10100];
int main()
{
    int n,a[23];
    for(int i=1;i<22;i++)
    a[i-1]=i*i*i;
    memset(d,0,sizeof(d));
    d[0]=1;
    for(int i=0;i<21;i++)
    for(int j=0;j<=10000;j++)
    if(j-a[i]>=0)d[j]+=d[j-a[i]];
    while(cin>>n)
    {
        cout<<d[n]<<endl;
    }
    return 0;
}
