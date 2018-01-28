#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int Search(char a[],char b[])
{        int len=strlen(a);
        int count=0;int ok=0;
        for(int i=0;b[i];i++)
        {
           int k=i;
           for(int j=0;a[j];j++)
           {
           if(a[j]==b[k++]&&(b[i+len]==' '||'\n'))count++;
           else {count=0;break;}
           }
           if(count==len)ok++;
        }
        cout<<ok;
}
int main()
{
    char a[100],b[10000];
    freopen("2.txt","r",stdin);
    cin>>a;
    int In,i=0;
    while((In=getchar())!=EOF)b[i++]=In;
    Search(a,b);
}
