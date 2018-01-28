#include<stdio.h>
#include<iostream>
#include<cstring>
const int N=1000;
using namespace std;
int main()
{
    char a[N],b[N],c[N],d[N];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(c));
    cin>>a>>b;
    int k=1,i;
    int len1=strlen(a),len2=strlen(b);
    if (len1<len2)k=0;
    else if(len1>len2)k=1;
    else if(len1==len2)
        for(i=0; b[i]; i++)
        {
            if(a[i]-b[i]>0)break;
            if(b[i]-a[i]>0)
            {
                k=0;
                break;
            }
        }
    if(!k)
        for(i=0; b[i]; i++)
        {
            d[i]=a[i];
            a[i]=b[i];
            b[i]=d[i];
        }
    strrev(a);
    strrev(b);
    int ok=0;
    for(i=0; a[i]; i++)
    {
        if(b[i])
        {
            if(a[i]>=b[i])c[i]=a[i]-b[i]+'0';
            if(a[i]<b[i]||ok)
            {
                c[i]=a[i]+10-b[i]+'0';
                ok=1;
            }
        }
        else
        {
            if(ok)c[i]=a[i]+9;
            else c[i]=a[i];
        }
        if(ok)
        {
            if(a[i+1]=='0')ok=1;
            else
            {
                a[i+1]-=1;
                ok=0;
            }
        }
    }
    strrev(c);
    int m=0;
    for(i=0; c[i]; i++)
        if(c[i]=='0')m=i+1;
        else break;
    if(k)
        cout<<c+m;
    else cout<<"-"<<c+m;
}
