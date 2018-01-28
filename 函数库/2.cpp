#include<iostream>
#include<cstdio>
using namespace std;
int II(int n)
{
    int sum=0;
    while(n%2==0)
    {
        n/=2;
        sum++;
    }
    return sum++;
}
int main()
{
    int a;
    while(cin>>a)
    {
        int sum=0;
        for(int i=1; i<=a; i++)
            if(a%2==0)sum+=II(i);
        cout<<sum<<endl;
    }

}
