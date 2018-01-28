#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=2*(n/3);
        if(n%3==2)sum++;
        cout<<sum<<endl;
    }
    return 0;
}
