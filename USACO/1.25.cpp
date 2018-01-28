/*
ID: 15588661
PROG: dualpal
LANG: C++
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int SSS(int s,int n,char a[])
{
    int i=0;
    while(s/n)
    {
        a[i++]=s%n+'0';
        s/=n;
    }
    a[i]=s+'0';
    a[i+1]='\0';
}
int palind(char a[])
{
    int len=strlen(a);
    int j=len-1;
    for(int i=0; i<len/2; i++,j--)
        if(a[i]!=a[j])return 0;
    return 1;
}
int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int N,S,id=1,ok=0;
    cin>>N>>S;
    char a[1000];
    for(int i=S+1;; i++)
    {
        int okk=0;
        for(int j=2; j<=10; j++)
        {
            SSS(i,j,a);
            if(palind(a))okk++;
            if(okk==2)
            {
                cout<<i<<endl;
                id++;
                if(id>N)
                {
                    ok=1;
                    break;
                }
                break;
            }
        }
        if(ok)break;
    }
    return 0;
}
