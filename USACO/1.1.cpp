/*
ID: 15588661
PROG: ride
LANG: C++
*/
#include<iostream>
#include<cstdio>
using namespace std;
char a[1000],b[1000];
int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    while(cin>>a>>b)
    {
        int s1=1,s2=1;
        for(int i=0;a[i];i++)
        s1*=a[i]-'A'+1;
        for(int i=0;b[i];i++)
        s2*=b[i]-'A'+1;
        if(s1%47==s2%47)cout<<"GO"<<endl;
        else cout<<"STAY"<<endl;
    }
    return 0;
}
