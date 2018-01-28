#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int T,id=1;
    long long a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        cin>>a>>b>>c;
        long long l=a*b*c,sum=0;
        cout<<"Case #"<<id++<<": ";
        cout<<a*b*c-1<<' '<<ceil(log2(a))+ceil(log2(b))+ceil(log2(c))<<endl;
    }
    return 0;
}
