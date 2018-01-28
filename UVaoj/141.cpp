#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#define MAX 401
using namespace std;
struct T
{
    int x[55][55],k;
    T*next;
} M[420];
int vis[430],S[55][55],N;
int hash()
{
    int v=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(S[i][j])v+=i*i*N+j*j;
    return v%MAX;
}
T*newnode()
{
    T*u=(T*)malloc(sizeof(T));
    u->next=NULL;
    return u;
}
int insert()
{
    int m=hash();
    T*u=newnode();
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        u->x[i][j]=S[i][j];
    if(!vis[m])
    {
        M[m].next=u;
        vis[m]=1;
    }
    else
    {
        u->next=M[m].next;
        M[m].next=u;
    }
}
int FZ()
{
    int  O[55][55];
    memset(O,0,sizeof(O));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(S[i][j])O[N-j-1][i]=1;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            S[i][j]=O[i][j];
}
int search()
{
    int m=hash();
    if(vis[m])
    {
        T*u=M[m].next;
        while(u!=NULL)
        {
            int ok=1;
            for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            if(S[i][j]!=u->x[i][j]&&ok)ok=0;
            if(ok)return 0;
            u=u->next;
        }
    }
    return 1;
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>N&&N)
    {
        int OK=1,d,x,y;
        char c;
        memset(S,0,sizeof(S));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<2*N; i++)
        {
            cin>>x>>y>>c;
            if(OK)
            {
                if(c=='+')S[x-1][y-1]=1;
                else S[x-1][y-1]=0;
                if(!search())
                {
                    OK=0;
                    d=i+1;
                }
                if(OK)
                {
                    for(int dd=0; dd<3; dd++)
                    {
                        insert();
                        FZ();
                    }
                    FZ();
                }
            }
        }
        if(!OK)cout<<"Player "<<d%2+1<<" wins on move "<<d<<endl;
        else cout<<"Draw"<<endl;
    }
    return 0;
}
