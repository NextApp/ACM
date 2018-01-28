#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int ok;
    char a[100],b[100];
    cin>>a>>b;
    int len1=strlen(a);
    int len2=strlen(b);
    if(len1>len2)ok=1;
    else if(len2>len1)ok=0;
    else
    for(int i=0;a[i];i++)
    if(a[i]>b[i]){ok=1;break;}
    else ok=0;
    if(ok)cout<<a;
    else cout<<b;
}
