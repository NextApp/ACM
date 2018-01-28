#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
#define MAX 1000001
using namespace std;
struct T
{
    char a[6][6];
    int x,y,v;
} q[MAX*2+1000];
struct H
{
    char a[6][6];
    H*next;
}A[MAX+1000];
int vis[MAX+1000];
int dx[]={-2,-2,2,2,-1,1,-1,1},dy[]={-1,1,-1,1,-2,-2,2,2};
char M[6][6],C[6][6],S[6][6];
H *newnode()
{
    H*u=(H*)malloc(sizeof(H));
    u->next=NULL;
    return u;
}
int hash()
{
    int s=0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            s+=C[i][j]*i*i*i*i*i*j*j*j*j;
    return s%MAX;
}
int insert()
{
    int m=hash();
    H*u=newnode();
    memcpy(u->a,C,sizeof(C));
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
int compare()
{
    int m=hash();
    if(vis[m])
    {
        H*u=A[m].next;
        while(u!=NULL)
        {
            if(memcmp(C,u->a,sizeof(C))==0)return 1;
            u=u->next;
        }
    }
    return 0;
}
int bfs(int i,int j)
{
    int rear=1,front=0;
    q[0].x=i,q[0].y=j,q[0].v=0;
    memcpy(q[0].a,M,sizeof(q[0].a));
    memcpy(C,M,sizeof(C));
    insert();
    while(front<rear)
    {
        memcpy(C,q[front].a,sizeof(q[front].a));
        int x=q[front].x,v=q[front].v,y=q[front++].y;
        if(v>10)return -1;
        if(memcmp(C,S,sizeof(S))==0)return v;
        for(int i=0; i<8; i++)
        {
            int newx=dx[i]+x,newy=dy[i]+y;
            if(newx>=0&&newy>=0&&newx<5&&newy<5)
            {
                C[x][y]=C[newx][newy];
                C[newx][newy]=' ';
                if(!compare())
                {
                    insert();
                    memcpy(q[rear].a,C,sizeof(C));
                    q[rear].x=newx,q[rear].y=newy,q[rear++].v=1+v;
                }
                C[newx][newy]=C[x][y];
                C[x][y]=' ';
            }
        }
    }
    return -1;
}
int main()
{
  //  freopen("1.txt","r",stdin);
    strcpy(S[0],"11111");
    strcpy(S[1],"01111");
    strcpy(S[2],"00 11");
    strcpy(S[3],"00001");
    strcpy(S[4],"00000");
    int n;
    cin>>n;
    getchar();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
            gets(M[j]);
        int result;
        memset(vis,0,sizeof(vis));
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                if(M[j][k]==' ')result=bfs(j,k);
        if(result>=0)cout<<"Solvable in "<<result<<" move(s)."<<endl;
        else cout<<"Unsolvable in less than 11 move(s)."<<endl;
    }
    return 0;
}
