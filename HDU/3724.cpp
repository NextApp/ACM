#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 302301
#define S 300001
using namespace std;
int n,m;
int M[N];
char b[40];
struct T
{
    int n;
    char s[32];
    T*next;
} A[N];
int hash()
{
    int len=strlen(b);
    int sum=0;
    for(int i=0;i<len;i++)
    sum=(sum+b[i]*b[i]*b[i])%S;
    return sum;
}
T*newnode()
{
    T*u=(T*)malloc(sizeof(T));
    if(u!=NULL)
    {
        u->next=NULL;
        u->n=0;
    }
    return u;
}
void build()
{
    int t=hash();
    if(!M[t])
    {
        M[t]=1;
        T*u=newnode();
        strcpy(u->s,b);
        u->n=1;
        A[t].next=u;
    }
    else
    {
        T*u=A[t].next,*o=newnode();
        while(u->next!=NULL)
        {
            u=u->next;
        }
        strcpy(o->s,b);
        o->n=1;
        u->next=o;
    }
}
int Search(int ok)
{
    int t=hash();
    if(M[t])
    {
        T*u=A[t].next;
        while(u!=NULL)
        {
            if(!strcmp(u->s,b))
            {
                if(!ok)u->n++;
                return u->n;
            }
            u=u->next;
        }
    }
    return 0;
}
int main()
{
  //  freopen("1.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        char a[40];
        memset(M,0,sizeof(M));
        for(int i=0; i<n; i++)
        {
            scanf("%s",a);
            int len=strlen(a);
            for(int j=1; j<=len; j++)
            {
                strcpy(b,a);
                b[j]='\0';
                int k=Search(0);
                if(!k)build();
            }
        }
        int ss=0;
        for(int i=0; i<m; i++)
        {
            int nu,u=0;
            scanf("%d",&nu);
            char d[40];
            for(int j=0; j<nu; j++)
            {
                double s[40],sum=0;
                for(int k=0; k<8; k++)
                {
                    scanf("%lf",&s[k]);
                    sum+=s[k];
                }
                char e=0;
                sum/=8;
                for(int k=0; k<8; k++)
                {
                    if(s[k]>sum)e+=pow(2,7-k);
                }
                d[u++]=e;
            }
            d[u]='\0';
            strcpy(b,d);
            int ll=Search(1);
            ss+=ll;
        }
        printf("%d\n",ss);
    }
    return 0;
}
