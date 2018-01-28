#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10100
using namespace std;
char a[maxn];
int n,l,t,s,k;
void build(int nu)
{
    a[nu]='\0';
    if(s<t&&nu==l)
    {
        s++;
        printf("%s\n",a);
        return;
    }
    if(s==t&&nu==l+1)
    {
        printf("%s\n",a);
        return;
    }
    a[nu]='0';
    build(nu+1);
    a[nu]='1';
    build(nu+1);
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        t=1,k=s=l=0;
        while(t*2<=n)
        {
            l++;
            t*=2;
        }
        t=n-((n-t)<<1);
        build(0);
    }
    return 0;
}
