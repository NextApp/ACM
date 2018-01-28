#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    while(cin>>n)
    {
        int num=0;
        if(n==1)num++;
        for(int i=1;i<n;i++)
            if(gcd(i,n)==1)num++;
        cout<<num<<endl;
    }
    return 0;
}
