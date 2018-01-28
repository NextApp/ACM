#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char m[1010][4010], c[4010];
void add(char a[],char b[],char d[])
{
    int lena=strlen(a);
    int lenb=strlen(b);
    int s=0,t,i;
    for(i=0; i<lena||i<lenb||s; i++)
    {
        t=s;
       if(i<lena)t+=a[i]-'0';
       if(i<lenb)t+=b[i]-'0';
        c[i]=t%10;
        s=t/10;
    }
    for(int j=0;j<i;j++)
    d[j]=c[j]+'0';
    d[i]='\0';
}
int main()
{
    m[0][0]='1',m[0][1]='\0';
    m[1][0]='2',m[1][1]='\0';
    for(int i=2;i<=1001;i++)
    add(m[i-1],m[i-2],m[i]);
    int n;
    while(cin>>n)
    {
        int len=strlen(m[n]);
        for(int i=len-1;i>=0;i--)
        cout<<m[n][i];
        cout<<endl;
    }
    return 0;
}
