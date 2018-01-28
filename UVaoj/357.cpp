#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long d[30100];
int a[]={1,5,10,25,30},n;
int main()
{
    memset(d,0,sizeof(d));
    d[0]=1;
    for(int i=0;i<5;i++)
    for(int j=0;j<=30000;j++)
    if(j-a[i]>=0)d[j]+=d[j-a[i]];
    while(cin>>n)
    {
        if(d[n]==1)cout<<"There is only "<<d[n]<<" way";
        else cout<<"There are "<<d[n]<<" ways";
        cout<<" to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}
