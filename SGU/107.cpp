#include<iostream>
#include<cstring>
#include<cstdio>
#define M 987654321
#define N 1000000000
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n<9)cout<<0<<endl;
        else if(n==9)cout<<8<<endl;
        else
        {
            cout<<72;
            for(int i=0; i<n-10; i++)
                cout<<'0';
            cout<<endl;
        }
    }
    return 0;
}
