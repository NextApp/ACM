/*
ID: 15588661
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int MMM(int n,int a,char m[])
{
    int i=0;
    while(n/a)
    {
        m[i++]=n%a+'0';
        n/=a;
    }
    m[i]=n+'0';
    m[i+1]='\0';
}
int SSS(int s,int n,int k,char b[])
{
    MMM(s,10,b);
    int i=0,sum=0;
    for(; b[i]; i++)
        sum+=(b[i]-'0')*pow(n,i);
    MMM(sum,k,b);
}
int palind(char a[])
{
    int len=strlen(a);
    int j=len-1;
    for(int i=0; i<len/2; i++,j--)
        if(a[i]!=a[j])return 0;
    return 1;
}
char M[10000],S[10000];
int main()
{

    int a;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    while(cin>>a)
    {
        for(int i=1; i<=300; i++)
        {
            SSS(i*i,10,a,S);
            if(palind(S))
            {
                SSS(i,10,a,M);
                int len1=strlen(M);
                for(int j=len1-1;j>=0; j--)
                    if(M[j]>'9')cout<<(char)(M[j]-'9'+'A'-1);
                    else cout<<M[j];
                cout<<' ';
                for(int j=0; S[j]; j++)
                    if(S[j]>'9')cout<<(char)(S[j]-'9'+'A'-1);
                    else cout<<S[j];
                cout<<endl;
            }
        }
    }
    return 0;
}
