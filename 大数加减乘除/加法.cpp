#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    const int N=10000;
    char a[N],b[N],c[N];
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int i=0,ok=0;
    cin>>a>>b;
    cout<<c<<endl;
    strrev(a);
    strrev(b);
    int g=0;
    for(int i=0;a[i]||b[i]||g;i++)
    {
        int x=g;
        if(a[i])x+=a[i]-'0';
        if(b[i])x+=b[i]-'0';
        g=x/10;
        c[i]=x%10+'0';
    }
    strrev(c);
    cout<<c;
}
