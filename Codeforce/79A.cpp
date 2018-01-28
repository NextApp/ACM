#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int lose;
int M(int a,int b,int k)
{
    if(k==1)
    {
        if(a>=2&&b>=2)M(a-2,b-2,2);
        else if(a>=1&&b>=12)M(a-1,b-12,2);
        else if(b>=22)M(a,b-22,2);
        else lose=1;
    }
    else
    {
        if(b>=22)M(a,b-22,1);
        else if(a>=1&&b>=12)M(a-1,b-12,1);
        else if(a>=2&&b>=2)M(a-2,b-2,1);
        else lose=2;
    }
}
int main()
{
    int x,y;
    while(cin>>x>>y)
    {
        lose=0;
        M(x,y,1);
        if(lose==2)cout<<"Ciel"<<endl;
        else cout<<"Hanako"<<endl;
    }
    return 0;
}
