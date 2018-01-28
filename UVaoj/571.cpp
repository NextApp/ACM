#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int vis[1020][1020],qq[101200];
struct T
{
    int x,y;
} q[1002000];
struct M
{
    int a,c;
}V[1001020];
char S[12][20];
int bfs(int x,int y,int r)
{
    int front=0,rear=1;
    memset(vis,0,sizeof(vis));
    vis[0][0]=1;
    q[0].x=0,q[0].y=0;
    V[0].a=-1;
    while(front<rear)
    {
        int xx=q[front].x,yy=q[front++].y;
        int X[8],Y[8];
        X[0]=x,Y[0]=yy;
        X[1]=0,Y[1]=yy;
        X[2]=xx,Y[2]=y;
        X[3]=xx,Y[3]=0;
        int m=xx+yy;
        X[4]=m<y?0:m-y;
        Y[4]=m>y?y:m;
        X[5]=m>x?x:m;
        Y[5]=m<x?0:m-x;
        for(int i=0; i<6; i++)
            if(!vis[X[i]][Y[i]])
            {
                V[rear].a=front-1;
                V[rear].c=i;
                if(Y[i]==r)
                {
                    int t=rear,s=0;
                    while(t>0)
                    {
                        qq[s++]=V[t].c;
                        t=V[t].a;
                    }
                    for(int j=s-1;j>=0;j--)
                    cout<<S[qq[j]]<<endl;
                    cout<<"success"<<endl;
                    return 0;
                }
                vis[X[i]][Y[i]]=vis[xx][yy]+1;
                q[rear].x=X[i];
                q[rear++].y=Y[i];
            }
    }
}
int main()
{
    strcpy(S[0],"fill A");
    strcpy(S[1],"empty A");
    strcpy(S[2],"fill B");
    strcpy(S[3],"empty B");
    strcpy(S[4],"pour A B");
    strcpy(S[5],"pour B A");
    int x,y,r;
    while(cin>>x>>y>>r)
    {
        bfs(x,y,r);
    }
    return 0;
}
