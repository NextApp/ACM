#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[]= {5,10,20,50,100,200,500,1000,2000,5000,10000};
double n;
long long d[30200];
int main()
{
    memset(d,0,sizeof(d));
    d[0]=1;
    for(int i=0; i<11; i++)
        for(int j=1; j<=30000; j++)
            if(j>=a[i])d[j]+=d[j-a[i]];
    while(cin>>n)
    {
        if(n==0.00)break;
        else
        {
            int m=(int)((n+0.0001)*100);
            printf("%6.2lf%17lld\n",n,d[m]);
        }
    }
    return 0;
}
