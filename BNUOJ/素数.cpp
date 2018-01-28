#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#define BLOCK 100000
#define X 4294967296
using namespace std;
long prim[1230][2]= {2,2*2, 3,2*3};
int tot=0;
void get_Ptable()
{
    long n=5,p2=9,kr=1,kp=2,k;
    while(1)
    {
        if(n==p2)
        {
            kr++;
            p2=prim[kr][0]*prim[kr][0];
            continue;
        }
        for(k=1; k<kr; k++)
        {
            if(n % prim[k][0]==0)goto nadd2;
        }
        prim[kp][0]=n;
        prim[kp][1]=n+n;
        if(++kp==1230)return;
nadd2:
        n=n+2;
    }
}
unsigned int S[6000000];
int prime[6000000],primenum=0;
int creatprime2()
{
    long n,k,BASE=0L,t1,t2;
    char *pp,*pw,*pend;
    get_Ptable(  );
    pp=(char*)malloc(BLOCK*sizeof(char));
    if(pp==NULL)return -1;
    do
    {
        pw=pp;
        pend=pp+BLOCK;
        do
        {
            *pw++=1;
        }
        while(pw<pend);
        if(BASE==0)pp[0]=pp[1]=0;
        for(k=0; k<1229; k++)
        {
            long ip=prim[k][0];
            long pi=prim[k][1]-BASE;
            for(n=pi; n<BLOCK; n+=ip)pp[n]=0;
            prim[k][1]=n+BASE;
        }
        for(k=0; k<BLOCK; k++)
            if(pp[k])
            {
                if(!primenum)S[0]=2;
                else
                {
                    unsigned long long s=((unsigned long long)S[primenum-1]*(k+BASE))%X;
                    S[primenum]=(unsigned int)s;
                }
                prime[primenum++]=k+BASE;
            }
        BASE+=BLOCK;
    }
    while(BASE<100000000);
    free(pp);
}
int m;
long long Pow(long long a,int n)
{
    long long s=1;
    for(int i=1; i<=n; i++)
        s*=a;
    return s;
}
long long M(int k)
{
    for(int i=1; i<=30; i++)
    {
        long long a=Pow(prime[k],i);
        if(a>m)return i-1;
    }
}
int B_search(int r,int first,int last)
{
    int k;
    while(first<=last)
    {
        k=first+(last-first)/2;
        int n1=M(k),n2=M(k+1);
        if(n1==r&&n2<r)return k;
        else if(n2>=r)first=k+1;
        else if(n1<r)last=k-1;
        else return -1;
    }
    return -1;
}

int main()
{
    int T,id=1;
    creatprime2();
    cin>>T;
    prime[primenum++]=100000007;
    for(int i=0; i<T; i++)
    {
        cin>>m;
        unsigned long long s=1;
        int last=lower_bound(prime,prime+primenum,m)-prime;
        int fa=M(0),first=0;
        while(fa>1)
        {
            int k=B_search(fa,first,last);
            if(k!=-1)s=(s*(unsigned long long)S[k])%X,first=k+1;
            else s=(s*(unsigned long long)S[first-1])%X;
            fa--;
        }
        if(prime[last]>m)last--;
        s=(s*(unsigned long long)S[last])%X;
        cout<<"Case "<<id++<<": "<<s<<endl;
    }
    return 0;
}
