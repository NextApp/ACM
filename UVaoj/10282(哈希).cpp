#include<iostream>
#include<cstring>
#include<cstdio>
#include<malloc.h>
#include<cmath>
#define MAX 100001
using namespace std;
struct T
{
    char  a[12],b[12];
    T *next;
} M[101000];
int vis[101000];
int hash(char a[])
{
    int v=0,len=strlen(a);
    for(int i=0; i<len; i++)
        v+=(a[i]-'a')*pow(6,len-i-1);
    return v%MAX;
}
T *newnode()
{
    T*u=(T*)malloc(sizeof(T));
    u->next=NULL;
    return u;
}
int insert(char a[],char b[])
{
    int h=hash(a);
    if(!vis[h])
    {
        T*u=newnode();
        strcpy(u->a,a);
        strcpy(u->b,b);
        M[h].next=u;
        vis[h]=1;
    }
    else
    {
        T*m=newnode();
        strcpy(m->a,a);
        strcpy(m->b,b);
        m->next=M[h].next;
        M[h].next=m;
    }
}
int search(char a[])
{
    int h=hash(a);
    if(vis[h])
    {
        T*u=M[h].next;
        while(u!=NULL)
        {
            if(!strcmp(u->a,a))
            {
                cout<<u->b<<endl;
                return 0;
            }
            u=u->next;
        }
    }
    cout<<"eh"<<endl;
}
int main()
{
    freopen("1.txt","r",stdin);
    char s[30];
    int OK=1;
    memset(vis,0,sizeof(vis));
    while(gets(s)!=NULL)
    {
        if(s[0]=='\0')
        {
            OK=0;
            continue;
        }
        if(OK)
        {
            int len=strlen(s),j=0;
            for(int i=0; i<len; i++)
                if(s[i]==' ')
                {
                    j=i;
                    break;
                }
            s[j]='\0';
            insert(s+j+1,s);
        }
        else search(s);
    }
    return 0;
}
