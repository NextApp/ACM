#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int A[10],h,k,M[1000];
int count(int i,int c,int value,int K)
{
    if(c==1)M[value]=1;
    else
    {
        for(int j=0; j+i<h+1; j++)
            count(i+j,c-1,value+j*A[K-c+1],K);
    }
}
int SSS(int K)
{
    memset(M,0,sizeof(M));
    count(0,K+1,0,K);
    for(int i=1; i<1000; i++)
        if(!M[i])return i-1;
}
int max1=0,L[10];
int calculate(int c,int value)
{
    if(c==k)
    {
        if(max1<=value)
           {
               for(int i=0;i<k;i++)L[i]=A[i];
               max1=value;
           }
    }
    else
    {
        for(int i=A[c-1]+1; i<=value+1; i++)
        {
            A[c]=i;
            calculate(c+1,SSS(c+1));
        }
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>h>>k)
    {
        if(!h&&!k)return 0;
        else
        {
            A[0]=1;
            max1=0;
            calculate(1,h);
            for(int i=0;i<k;i++)
            printf("%3d",L[i]);
            printf(" ->%3d\n",max1);
        }
    }
    return 0;
}
