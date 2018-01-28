#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cmath>
#include<cstring>
#define N 300001
using namespace std;
struct T
{
    char a[4][4],L[60];
    int x,y,len;
} q[N+1000];
struct H
{
    char a[4][4];
    H*next;
} A[N+1000];
int vis[N+1000];
char M[4][4];
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};
char cy[4]= {'U','R','D','L'};
H*newnode()
{
    H*u=(H*)malloc(sizeof(H));
    u->next=NULL;
    return u;
}
int hash()
{
    int s=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            s+=(M[i][j]-'0')*pow(10,3*i+j);
    return s%N;
}
int insert()
{
    int m=hash();
    H*u=newnode();
    memcpy(u->a,M,sizeof(M));
    if(!vis[m])
    {
        A[m].next=u;
        vis[m]=1;
    }
    else
    {
        u->next=A[m].next;
        A[m].next=u;
    }
}
int search()
{
    int m=hash();
    if(vis[m])
    {
        H*u=A[m].next;
        while(u!=NULL)
        {
            if(!memcmp(u->a,M,sizeof(M)))return 1;
            u=u->next;
        }
    }
    return 0;
}
int bfs(int a,int b)
{
    int rear=1,front=0;
    q[0].len=0,q[0].x=a,q[0].y=b,q[0].L[0]='\0';
    memcpy(q[0].a,M,sizeof(M));
    while(front<rear)
    {
        memcpy(M,q[front].a,sizeof(q[front].a));
        char L[60];
        strcpy(L,q[front].L);
        int x=q[front].x,y=q[front].y,len=q[front++].len;
        for(int i=0; i<4; i++)
        {
            int nx=dx[i]+x,ny=dy[i]+y;
            if(nx>=0&&ny>=0&&nx<3&&ny<3)
            {
                M[x][y]=M[nx][ny];
                M[nx][ny]='0';
                if(!search())
                {
                    insert();
                    memcpy(q[rear].a,M,sizeof(M));
                    q[rear].len=len+1;
                    q[rear].x=nx,q[rear].y=ny;
                    strcpy(q[rear].L,L);
                    q[rear].L[len]=cy[i],q[rear++].L[len+1]='\0';
                }
                M[nx][ny]=M[x][y];
                M[x][y]='0';
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
            cout<<M[i][j]<<' ';
        cout<<M[i][2]<<endl;
    }
    cout<<q[rear-1].L<<endl;
}
int main()
{
    freopen("1.txt","r",stdin);
    int n,id=1;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
                cin>>M[j][k];
        cout<<"Puzzle #"<<id++<<endl;
        int ok=1;
        for(int j=0; j<3&&ok; j++)
            for(int k=0; k<3&&ok; k++)
            {
                if(M[j][k]=='0')
                    {bfs(j,k);ok=0;}
            }
        cout<<endl;
    }
    return 0;
}
