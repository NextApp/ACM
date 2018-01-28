#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{

    int i=0,count=0,b[100][1000];
    char a[100][1000];
    while(gets(a[i++]))count++;
    for(int i=0,k=0; i<count; i++,k++)
    {int ok=0;
    for(int j=0,m=0;a[i][j];j++)
   {
    if(a[i][j]==' ')ok=0;
    else if(ok)b[k][m-1]=b[k][m-1]*10+a[i][j]-'0';
    else if(!ok){b[k][m++]=a[i][j]-'0';ok=1;}
   }
    }
   for(int i=0;i<count;i++)
   {
   for(int j=0;b[i][j];j++)
   cout<<b[i][j];
   cout<<endl;
   }
}
