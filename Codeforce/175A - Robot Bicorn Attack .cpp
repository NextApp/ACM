#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000000
using namespace std;
char a[100];
int D(int i,int j)
{
    if(j-i>1&&a[i]=='0')return -1;
    int s=0;
    for(int k=i; k<j; k++)
    {
        s=10*s+a[k]-'0';
        if(s>N)
            return -1;
    }
    return s;
}
int main()
{
    while(cin>>a)
    {
        int len=strlen(a);
        int m=-1;
        for(int i=1; i<len-1; i++)
            for(int j=i+1; j<len; j++)
            {
                int s=0;
                int okk=1;
                int ok=D(0,i);
                if(ok!=-1&&ok<=N)s+=ok;
                else okk=0;
                ok=D(i,j);
                if(ok!=-1&&ok<=N)s+=ok;
                else okk=0;
                ok=D(j,len);
                if(ok!=-1&&ok<=N)s+=ok;
                else okk=0;
                if(okk)m=max(m,s);
            }
        cout<<m<<endl;
    }
    return 0;
}
