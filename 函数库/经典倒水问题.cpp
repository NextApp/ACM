#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c,d,vis[230][230],C[240];
struct T
{
    int a,b,v;
} q[40200];
int bfs()
{
    int rear=1,front=0;
    q[0].v=0,q[0].a=0,q[0].b=0;
    while(front<rear)
    {
        int x=q[front].a;
        int y=q[front].b;
        int v=q[front++].v;
        int z=c-x-y;
        int x0=x,y0=y,v0,X[10],Y[10],V[10],k=0;
        if(x+y>=a)
        {
            x0=a;
            y0=x+y-a;
            v0=a-x0;
        }
        else
        {
            x0=x+y;
            y0=0;
            v0=y;
        }
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        if(x+z>=a)
        {
            x0=a;
            y0=y;
            v0=a-x;
        }
        else
        {
            x0=x+z;
            y0=y;
            v0=z;
        }
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        if(x+y>=b)
        {
            x0=x+y-b;
            y0=b;
            v0=b-y;
        }
        else
        {
            x0=0;
            y0=x+y;
            v0=x;
        }
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        if(y+z>=b)
        {
            y0=b;
            x0=x;
            v0=b-y;
        }
        else
        {
            y0=y+z;
            v0=z;
            x0=x;
        }
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        x0=0,y0=y,v0=x;
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        y0=0,x0=x,v0=y;
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        for(int i=0; i<k; i++)
        {
            if(!vis[X[i]][Y[i]])
            {
               // if(d==4)cout<<X[i]<<' '<<Y[i]<<V[i]<<' '<<i<<' '<<v<<endl;
                vis[X[i]][Y[i]]=vis[x][y]+1;
                if(C[c-X[i]-Y[i]]==-1)C[c-X[i]-Y[i]]=v+V[i];
                if(C[Y[i]]==-1)C[Y[i]]=v+V[i];
                if(C[X[i]]==-1)C[X[i]]=v+V[i];
                if(C[d]!=-1)return vis[x][y];
                q[rear].a=X[i];
                q[rear].b=Y[i];
                q[rear++].v=V[i]+v;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c>>d;
        memset(vis,0,sizeof(vis));
        memset(C,-1,sizeof(C));
        vis[0][0]=1;
        C[c]=C[0]=0;
        bfs();
        for(int j=d; j>=0; j--)
            if(C[j]!=-1)
            {
                cout<<C[j]<<' '<<j<<endl;
                break;
            }
    }
    return 0;
}
