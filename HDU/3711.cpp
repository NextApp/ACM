#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n,a[120];
int count(int a,int b)
{
    int c=0;
    while(a/2&&b/2)
    {
        if(a%2!=b%2)c++;
        a/=2,b/=2;
    }
    if(a%2!=b%2)c++;
    if(a/2)
    {
        a/=2;
        while(a/2)
        {
            if(a%2)c++;
            a/=2;
        }
        if(a)c++;
    }
    if(b/2)
    {
        b/=2;
        while(b/2)
        {
            if(b%2)c++;
            b/=2;
        }
        if(b)c++;
    }
    return c;
}
void judge(int b)
{
    int mm=1000,j;
    for(int i=0; i<m; i++)
    {
        int s=count(a[i],b);
        if(s<=mm)
        {
            if(s==mm&&a[j]>a[i])j=i;
            else if(s<mm) j=i;
            mm=s;
        }
    }
    printf("%d\n",a[j]);
}
int main()
{
    int T;
   // freopen("1.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
        {
            int b;
            scanf("%d",&b);
            judge(b);
        }
    }
    return 0;
}
