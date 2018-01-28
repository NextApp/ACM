
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int In;
    freopen("2.txt","r",stdin);
    int a[100][200];
    int LEN[100];
    int ok=0,i=0,j=0;
    while((In=getchar())!=EOF)
    {
        if(In==' ')ok=0;
        else if(In=='\n')
        {
            LEN[i]=j;
            i++;j=0;ok=0;
        }
        else
        {
            if(ok)a[i][j-1]=a[i][j-1]*10+In-'0';
            else
            {
                a[i][j++]=In-'0';
                ok=1;
            }
        }
    }
    int count=i;
    for(i=0; i<count; i++)
    {
        for(j=0;j<LEN[i]; j++)
            cout<<a[i][j]<<' ';
            cout<<endl;
    }
}
