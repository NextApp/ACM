#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
void gcd_exp(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd_exp(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    LL x,y,m,n,L;
    int id=1;
    while(cin>>x>>y>>m>>n>>L)
    {
        LL a=n-m,b=L,xx,yy,d,c=x-y;
        gcd_exp(a,b,d,xx,yy);
        int OK=1;
        if(!a||c%d!=0)OK=0;
        c/=d;
        b/=d;
        xx*=c;
        if(b<0)b=-b;
        xx=(xx%b+b)%b;
        if(OK)cout<<xx<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
