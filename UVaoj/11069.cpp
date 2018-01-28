#include<iostream>
using namespace std;
long long a[100]={0,1,2,2};
int main()
{
    for(int i=4;i<=76;i++)
        a[i]=a[i-2]+a[i-3];
    int n;
    while(cin>>n)cout<<a[n]<<endl;
    return 0;
}
