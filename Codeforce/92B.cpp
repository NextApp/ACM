#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int cnt,n;
char a[1200000],b[1200000];
int A(int len)
{
    if(len==0&&a[0]=='1')return 0;
    cnt++;
    if(a[len]=='1')
    {
        int i=len,ok=0;
        for(; i>=0; i--)
        {
            if(a[i]=='1')a[i]='0';
            else
            {
                ok=1;
                a[i]='1';
                break;
            }
        }
        if(!ok)
        {
            strcpy(b,a);
            a[0]='1';
            strcpy(a+1,b);
            len++;
            a[len]='\0';
        }
        A(len);
    }
    else
    {
        a[len]='\0';
        A(len-1);
    }
}
int main()
{
  //  freopen("1.txt","r",stdin);
    while(scanf("%s",a)==1)
    {
        cnt=0;
        int len=strlen(a);
        A(len-1);
        printf("%d\n",cnt);
    }
    return 0;
}
