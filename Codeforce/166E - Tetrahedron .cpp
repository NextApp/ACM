#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000000007
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long e=0;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)e=(3*e+3)%N;
            else e=(3*e-3)%N;
        }
        cout<<e<<endl;
    }
    return 0;
}
