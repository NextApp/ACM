#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5005
#define INF 1000000
using namespace std;
int m,n,num;
char A[N][1000],M[100000];
bool vis[N][N];
int q[12000];
void init()
{
    memset(vis,false,sizeof(vis));
    strcpy(A[0],"Erdos, P.");
}
int v[N],d[N];
void bfs()
{
    memset(d,-1,sizeof(d));
    d[0]=q[0]=0;
    int front=0,rear=1;
    while(front<rear)
    {
        int u=q[front++];
        for(int i=1;i<num;i++)
        if(d[i]==-1&&vis[u][i])
        {
            d[i]=d[u]+1;
            q[rear++]=i;
        }
    }
}
void solve()
{
    for(int i=0,j; i<n; i++)
    {
        gets(M);
        printf("%s ",M);
        for(j=0; j<num; j++)
            if(!strcmp(A[j],M))
                break;
        if(d[j]==-1)printf("infinity");
        else printf("%d",d[j]);
        printf("\n");
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Scenario %d\n",id++);
        scanf("%d%d",&m,&n);
        getchar();
        init();
        num=1;
        for(int i=0; i<m; i++)
        {
            gets(M);
            bool f[N]= {false};
            char name[1000];
            int len=0,l=strlen(M);
            for(int j=0; j<l; j++)
            {
                if(len!=0||M[j]!=' ')
                    name[len++]=M[j];
                if((j>1&&M[j-1]=='.'&&M[j]==',')||M[j]==':')
                {
                    len--;
                    name[len]='\0';
                    int ok=0;
                    for(int k=0; k<num; k++)
                        if(!strcmp(name,A[k]))
                        {
                            f[k]=true;
                            ok=1;
                            break;
                        }
                    if(!ok)
                    {
                        f[num]=true;
                        strcpy(A[num++],name);
                    }
                    len=0;
                    if(M[j]==':')break;
                }
            }
            for(int j=0; j<num-1; j++)
                if(f[j])
                {
                    for(int k=j+1; k<num; k++)
                        if(f[k])vis[j][k]=vis[k][j]=true;
                }
        }
        bfs();
        solve();
    }
    return 0;
}
