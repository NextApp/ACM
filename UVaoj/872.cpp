#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct T
{
    int num;
    char a[30];
} q[100];
int vis[120],M[120][120],s,n,k,OK;
char A[100000][25];
void topo(char u)
{
    vis[u]=-1;
    for(int i=1; i<q[u].num; i++)
    {
        if(vis[q[u].a[i]]<0)OK=0;
        if(!vis[q[u].a[i]])topo(q[u].a[i]);
    }
    vis[u]=1;
    int o=s;
    for(int i=0,j; i<=o; i++)
    {
        for(j=k; j<n; j++)if(M[u][A[i][j]])break;
        A[i][k-1]=u;
        for(int t=k; t<j; t++)
        {
            s++;
            for(int m=k-1,y=k; m<n; m++)
            {
                if(t==m)A[s][m]=u;
                else A[s][m]=A[i][y++];
            }
        }
    }
    k--;
}
int cmp(const void *_a,const void*_b)
{
    char *a=(char*)_a;
    char *b=(char*)_b;
    return strcmp(a,b);
}
int main()
{
    int numcase;
    //freopen("1.txt","r",stdin);
    cin>>numcase;
    getchar();
    for(int i=0; i<numcase; i++)
    {
        getchar();
        if(i)cout<<endl;
        char a[500];
        k=0;
        gets(a);
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        for(int j='A'; j<='Z'; j++)q[j].num=0;
        for(int j=0; a[j]; j++)if(a[j]>='A'&&a[j]<='Z')q[a[j]].num=1,k++;
        s=0,n=k;
        gets(a);
        int ok=0,c;
        for(int j=0; a[j]; j++)
        {
            if(a[j]>='A'&&a[j]<='Z')
            {
                if(ok)
                {
                    q[c].a[q[c].num++]=a[j];
                    M[c][a[j]]=1;
                    ok=0;
                    continue;
                }
                c=a[j];
                ok=1;
            }
        }
        OK=1;
        for(int j='A'; j<='Z'; j++)
            if(q[j].num&&!vis[j])topo(j);
        qsort(A,s+1,sizeof(A[0]),cmp);
        if(OK)
        {
            for(int j=0; j<=s; j++)
            {
                for(int t=0; t<n-1; t++)
                    cout<<A[j][t]<<' ';
                cout<<A[j][n-1]<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
