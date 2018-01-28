#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define N 1200
using namespace std;
long long x,a,b;
int len;
char X[100];
long long S(long long m,int ok)
{
    long long result=m/pow(10,len);
    long long t=pow(10,len);
    if(m%t==x&&!ok)result--;
    if(m%t>=x)result++;
    return result;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        cin>>X>>a>>b;
        len=strlen(X);
        sscanf(X,"%lld",&x);
        cout<<S(b,1)-S(a,0)<<endl;
    }
    return 0;
}
