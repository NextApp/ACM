#include<iostream>
#include<cstdio>
using namespace std;
int a[100100];
int main()
{
    int n,m,min=101000;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
        if(min>a[i])min=a[i];
    }
    int sum=(min-1)*m*m;
    for(int s=0; s<m; s++)
        sum+=(a[s]-min)*m;
    cout<<sum<<endl;
}
