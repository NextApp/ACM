#include<iostream>
using namespace std;
int main()
{
    double n,y;
    int x;
    cin>>n>>x>>y;
    int m=(int)((y/100.0)*n);
    if(y*n/100.0>m)m++;
    if(m>x)cout<<m-x<<endl;
    else cout<<0<<endl;
    return 0;
}
