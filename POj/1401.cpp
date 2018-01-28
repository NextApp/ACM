#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long m,sum=0;
        long long l=5;
        cin>>m;
        while(m/l)
        {
            sum+=m/l;
            l*=5;
        }
        cout<<sum<<endl;
    }
    return 0;
}
