#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long maxpraime(long long a)
{
    long long s=1,b=a;
    for(long long i=2; i<=b; i++)
    {
        while(!(b%i))
        {
            b/=i;
            s=i;
        }
        if(i>sqrt(b)&&i>s)return b;
    }
    return s;
}
int main()
{
    long long s;
    while(cin>>s)
        cout<<maxpraime(s)<<endl;
}
