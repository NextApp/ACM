#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void add(char a[],char b[],char c[],int ok)
{
    int lena =strlen(a);
    int lenb =strlen(b);
    for(int i=0;i<lena;i++)a[i]-='0';
    for(int j=0;j<lenb;j++)b[j]-='0';
    int g=0,i=0;
    for(;i<lena||i<lenb||g;i++)
    {
        if(i<lena)g+=a[i];
        if(i<lenb)g+=b[i];
        c[i]=g%10+'0';
        g/=10;
    }
    c[i]='\0';
    if(ok)for(int i=0;i<lena;i++)a[i]+='0';
    for(int j=0;j<lenb;j++)b[j]+='0';
}
char a[260][100];
int main()
{
    int n=250;
    memset(a,0,sizeof(a));
    a[0][0]='1';
    a[1][0]='1';
    a[2][0]='3';
    for(int i=3;i<=250;i++)
    {
        add(a[i-1],a[i-2],a[i],1);
        add(a[i],a[i-2],a[i],0);
    }
    while(cin>>n)
    {
        int len=strlen(a[n]);
        for(int i=len-1;i>=0;i--)
        cout<<a[n][i];
        cout<<endl;
    }
    return 0;
}
