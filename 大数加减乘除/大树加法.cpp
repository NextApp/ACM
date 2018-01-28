#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100],b[100],c[100];
    memset(c,0,sizeof(c));
    int i=0,j=0,ok=0;
    cin>>a>>b;
    cout<<c<<endl;
    strrev(a);
    strrev(b);
    int len1=strlen(a);
    int len2=strlen(b);
    int max=len1>len2?len1:len2;
    int min=len1<len2?len1:len2;
    for(i=0; i<max||ok==1; i++)
    {
        if(i<min)c[i]+=(a[i]+b[i]-'0');
        else if(len1==min&&len1!=len2)c[i]+=b[i];
        else if(len2==min&&len1!=len2)c[i]+=a[i];
        if(c[i]>'9')
        {
            if(!a[i+1]&&!b[i+1])c[i+1]+='1';
            else
            c[i+1]+=1;
            c[i]-=10;
            ok=1;
        }
        else ok=0;
    }
    strrev(c);
    cout<<c;
}
