#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 220
using namespace std;
typedef struct
{
    int a,b,v;
} Node;
int a,b,c,d,C[N],vis[N][N];
struct cmp
{
    bool operator()(const Node&a,const Node&b)
    {
        return a.v>b.v;
    }
};
Node *q=new Node[N*N];
int bfs()
{
    q[0].a=0,q[0].b=0,q[0].v=0;
    priority_queue<Node,vector<Node>,cmp>Q(q,q+1);
    while(!Q.empty())
    {
        Node u=Q.top();
        int x=u.a,y=u.b,z=c-x-y,v=u.v;
        int x0,y0,v0,X[10],Y[10],V[10],k=0;
        Q.pop();
        if(x+y>=a)
        {
            x0=a;
            y0=x+y-a;
            v0=a-x;
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
        if(y+x>=b)
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
            x0=x;
            y0=b;
            v0=b-y;
        }
        else
        {
            x0=x;
            y0=y+z;
            v0=z;
        }
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        x0=0,y0=y,v0=x;
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        x0=x,y0=0,v0=y;
        X[k]=x0,Y[k]=y0,V[k++]=v0;
        for(int i=0; i<k; i++)
        {
            int o=X[i],t=Y[i];
            if(!vis[o][t])
            {
                vis[o][t]=1;
                if(C[o]==-1)C[o]=v+V[i];
                if(C[t]==-1)C[t]=v+V[i];
                if(C[c-o-t]==-1)C[c-o-t]=v+V[i];
                if(C[d]!=-1)return 1;
                else
                {
                    Node m;
                    m.a=o,m.b=t,m.v=v+V[i];
                    Q.push(m);
                }
            }
        }
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c>>d;
        memset(vis,0,sizeof(vis));
        memset(C,-1,sizeof(C));
        C[0]=C[c]=0;
        vis[0][0]=1;
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
