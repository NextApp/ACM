#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,num;
char M[1200][200];
char S[120];
struct T
{
    int n,c,a[30];
} A[1200];
int v[30];
int check(int n)
{
    int vis[30];
    memset(vis,0,sizeof(vis));
    int mm=0,ll=1200,t,l;
    for(int i=0; i<num; i++)
    {
        while(v[A[i].a[A[i].c]]&&A[i].c<n)A[i].c++;
        if(A[i].c<n)vis[A[i].a[A[i].c]]++;
    }
    for(int i=1; i<=n; i++)
        if(!v[i])
        {
            if(mm<vis[i])mm=vis[i],l=i;
            if(vis[i]&&vis[i]<ll)ll=vis[i];
        }
    if(ll==mm)
    {
        for(int i=1; i<=n; i++)
            if(!v[i]&&vis[i]==ll)printf("%s\n",M[i-1]);
        return 1;
    }
    else if(ll>=num/2+1)
    {
        printf("%s\n",M[l-1]);
        return 1;
    }
    else
    {
        for(int i=1;i<=n;i++)
        if(vis[i]==ll)v[i]=1;
        for(int i=0; i<num; i++)
            if(v[A[i].a[A[i].c]])A[i].c++;
    }
    return 0;
}
int main()
{
    freopen("1.txt","r",stdin);
    int T,id=0;
    scanf("%d",&T);
    while(T--)
    {
        if(id)printf("\n");
        id=1;
        scanf("%d",&n);
        gets(S);
        for(int i=0; i<n; i++)
            gets(M[i]);
        num=0;
        memset(v,0,sizeof(v));
        while(gets(S)!=NULL)
        {
            if(S[0]=='\0')break;
            stringstream fin(S);
            A[num].n=0,A[num].c=0;
            int a;
            while(fin>>a)A[num].a[A[num].n++]=a;
            num++;
        }
        while(1)
        {
            if(check(n))
            {
                break;
            }
        }
    }
    return 0;
}
