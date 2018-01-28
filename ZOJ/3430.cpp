#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define N 2100
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n,m,d[20000];
char a[N][N],b[N][N],F[20000];
int LEN[600],C[150];
char T[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int SSS(char a[],char b[])
{
    int kk=0,k=0;
    for(int i=0; a[i]; i++)
    {
        if(a[i]=='=')
        {
            kk+=2;
            continue;
        }
        int u=C[a[i]],t=5+k;
        while(u)
        {
            d[t--]=u%2;
            u=u>>1;
        }
        while(t>=k)d[t--]=0;
        k+=6;
    }
    k-=kk;
    int s=0;
    for(int i=0; i<k; i+=8)
    {
        int t=0;
        for(int j=0; j<8; j++)
            t+=d[i+j]*(1<<(7-j));
        b[s++]=t;
    }
    b[s]=0;
    return s;
}
int nextval[N];
void get(char a[],int plen)
{
    int i=0;
    nextval[i]=-1;
    int j=-1;
    while(i<plen-1)
    {
        if(j==-1||a[i]==a[j])
        {
            ++i;
            ++j;
            if(a[i]!=a[j])nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}
int Kmp(char a[],char b[],int lena,int lenb)
{
    int i=0,j=0;
    get(a,lena);
    while(i<lenb&&j<lena)
    {
        if(j==-1||a[j]==b[i])
        {
            ++i;
            ++j;
        }
        else j=nextval[j];
    }
    if(j==lena)return 1;
    return 0;
}
int main()
{
    for(int i=0;i<64;i++)
    C[T[i]]=i;
   // freopen("1.txt","r",stdin);
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",F);
            LEN[i]=SSS(F,a[i]);
        }
        scanf("%d",&m);
        for(int j=0; j<m; j++)
        {
            scanf("%s",F);
            int lenb=SSS(F,b[j]),sum=0;
            for(int i=0; i<n; i++)
                sum+=Kmp(a[i],b[j],LEN[i],lenb);
            printf("%d\n",sum);
        }
        printf("\n");
    }
    return 0;
}
