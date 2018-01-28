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
    for(i=0; b[i]||a[i]||ok==1; i++)
    {
        if(b[i]&&a[i])c[i]+=(a[i]+b[i]-'0');
        else c[i]+=b[i]>a[i]?b[i]:a[i];
        while(c[i]>'9')
        {
            if(!a[i+1]&&!b[i+1])c[i+1]+='1';
            else
            c[i+1]+=1;
            c[i]-=10;
            ok=1;
        }
        if(c[i]<='9') ok=0;
    }
    strrev(c);
    cout<<c;
}
