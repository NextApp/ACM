#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define INF 1e9
using namespace std;
long double a[300000];
int M[300000];
long long s[50000];
int prime()
{
    memset(M,0,sizeof(M));
    for(int i=2; i<=500; i++)
        for(int j=i+i; j<=249439; j+=i)
            M[j]=1;
}
void init()
{
    int k=2;
    s[0]=2,s[1]=3;
    a[1]=a[2]=1;
    a[3]=2;
    for(int i=4; i<=41; i++)
    {
        a[i]=a[i-1]+a[i-2];
        if(!M[i])s[k++]=a[i];
    }
    for(int i=42; i<=249439; i++)
    {
        if(a[i-2]>a[i-1])a[i-2]/=10;
        long double l=a[i-1]+a[i-2];
        if(l>=INF)a[i]=l/10.;
        else a[i]=l;
        if(!M[i])s[k++]=(long long)a[i];
    }
}
int main()
{
    prime();
    init();
    int n;
    while(cin>>n)
    {
        cout<<s[n-1]<<endl;
    }
    return 0;
}
