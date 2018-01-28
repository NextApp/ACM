#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1000;
int main()
{
    char a[N],b[N],c[N];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>a>>b;
    strrev(a);strrev(b);
    int i,j;
    for(i=0;a[i];i++)
    {
        for(j=0;b[j];j++)
        {
            c[i+j]+=(a[i]-'0')*(b[j]-'0');
            if(c[i+j]>9){c[i+j+1]+=c[i+j]/10;c[i+j]%=10;}
        }
    }
    int len1=strlen(a),len2=strlen(b);
    i=len1+len2;
    while(i>1&&!c[i-1])--i;
    while(i>0)
    c[--i]+='0';
    strrev(c);
    cout<<c;
}
