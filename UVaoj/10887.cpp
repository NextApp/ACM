#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
#define MAX 2250001
using namespace std;
char  m[1600][12],n[1600][12];
int vis[2260000];
struct T
{
    char a[22];
    T* next;
} S[2260000];
T *newnode()
{
    T*u=(T*)malloc(sizeof(T));
    u->next=NULL;
    return u;
}
int hash(char a[])
{
    int v=0,lena=strlen(a);
    for(int i=0; i<lena; i++)
        v+=(a[i]-'a')*1<<(2,lena-i+1);
    return v%MAX;
}
int insert(char a[])
{
    int m=hash(a);
    T*u=newnode();
    strcpy(u->a,a);
    if(!vis[m])
    {
        S[m].next=u;
        vis[m]=1;
        return 1;
    }
    else
    {
        T*o=S[m].next;
        while(o!=NULL)
        {
            if(!strcmp(o->a,a))return 0;
            if(o->next==NULL)
            {
                o->next=u;
                break;
            }
            o=o->next;
        }
    }
    return 1;
}
int main()
{
    int test;
   freopen("1.txt","r",stdin);
    cin>>test;
    for(int i=0; i<test; i++)
    {
        int M,N;
        memset(vis,0,sizeof(vis));
        cin>>M>>N;
        getchar();
        for(int j=0; j<M; j++)
            gets(m[j]);
        for(int j=0; j<N; j++)
               gets(n[j]);
        int ok=0;
        for(int j=0; j<M; j++)
            for(int k=0; k<N; k++)
            {
                int l=strlen(m[j]);
                char c[22];
                strcpy(c,m[j]);
                strcpy(c+l,n[k]);
                if(insert(c))ok++;
            }
        cout<<"Case "<<i+1<<": "<<ok<<endl;
    }
    return 0;
}
