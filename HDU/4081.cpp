#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 100000000
#define N 1200
struct T
{
    double x,y,r;
} M[N];
struct Tree
{
    int a[N],n;
} tree[N];
struct V
{
    int a;
    double edge;
} v[N];
struct O
{
    int a,b;
} tre[N];
int n,vis[N],sm,mm;
double m[N][N],sum;
int MinTree()
{
    for(int i=0; i<n; i++)
    {
        tree[i].n=0;
        v[i].edge=INF;
    }
    sum=v[0].edge=0;
    int j=n-1,f=0,k=0;
    while(j--)
    {
        for(int i=1; i<n; i++)
            if(v[i].edge&&m[i][f]&&m[i][f]<v[i].edge)
            {
                v[i].edge=m[i][f];
                v[i].a=f;
            }
        double minedge=INF;
        for(int i=1; i<n; i++)
            if(v[i].edge&&v[i].edge<minedge)
            {
                minedge=v[i].edge;
                f=i;
            }
        v[f].edge=0;
        int s=v[f].a;
        tree[f].a[tree[f].n++]=s;
        tree[s].a[tree[s].n++]=f;
        tre[k].a=f,tre[k++].b=s;
        sum+=minedge;
    }
}
int dfs(int x)
{
    vis[x]=1;
    if(M[x].r>mm)mm=M[x].r;
    for(int i=0; i<tree[x].n; i++)
        if(!vis[tree[x].a[i]])dfs(tree[x].a[i]);
    vis[x]=0;
}
int small()
{
    double maxx=0;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n-1; i++)
    {
        int x=tre[i].a,y=tre[i].b;
        mm=M[x].r;
        vis[x]=vis[y]=1;
        dfs(x);
        if(sm==mm)
        {
            mm=M[y].r;
            vis[x]=1;
            dfs(y);
        }
        double ss=(sm+mm)/(sum-m[x][y]);
        if(ss>maxx)maxx=ss;
        vis[x]=vis[y]=0;
    }
    printf("%.2lf\n",maxx);
}
int main()
{
 // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(M,0,sizeof(M));
        memset(m,0,sizeof(m));
        scanf("%d",&n);
        sm=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf%lf",&M[i].x,&M[i].y,&M[i].r);
            if(sm<M[i].r)sm=M[i].r;
        }
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                m[j][i]=m[i][j]=sqrt((M[i].x-M[j].x)*(M[i].x-M[j].x)+(M[i].y-M[j].y)*(M[i].y-M[j].y));
        MinTree();
        small();
    }
    return 0;
}
