#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct T
{
    int num;
    char a[25];
} q[127];
char A[100000][25];
int vis[130],M[130][130],k,s,n;
void topo(char u)
{
    vis[u]=1;
    for(int i=1; i<q[u].num; i++)
        if(!vis[q[u].a[i]])topo(q[u].a[i]);
    int o=s,j;
    for(int i=0; i<=o; i++)
    {
        for(j=k; j<n; j++)if(M[u][A[i][j]])break;
        int ss;
        for(int t=k-1; t<j; t++)
        {
            if(t==k-1)ss=i;
            else ss=++s;
            for(int m=k-1,y=k; m<n; m++)
            {
                if(t==m)A[ss][m]=u;
                else A[ss][m]=A[i][y++];
                A[ss][n]=0;
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
    char a[500];
    int id=0;
    //freopen("1.txt","r",stdin);
    while(gets(a)!=NULL)
    {
        char c;
        int ok=0;
        if(id)cout<<endl;
        id++;
        k=0;
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        for(int i='a'; i<='z'; i++)q[i].num=0;
        for(int i=0; a[i]; i++)
        {
            if(a[i]<='z'&&a[i]>='a')
            {
                q[a[i]].num=1;
                q[a[i]].a[0]=a[i];
                k++;
            }
        }
        gets(a);
        for(int i=0; a[i]; i++)
        {
            if(a[i]<='z'&&a[i]>='a')
            {
                if(ok)
                {
                    q[c].a[q[c].num++]=a[i];
                    M[c][a[i]]=1;
                    ok=0;
                    continue;
                }
                c=a[i];
                ok=1;
            }
        }
        s=0,n=k;
        for(int i='a'; i<='z'; i++)
            if(q[i].num&&!vis[i])topo(i);
        qsort(A,s+1,sizeof(A[0]),cmp);
        for(int i=0; i<=s; i++)
        {
            for(int j=0; j<n; j++)
                cout<<A[i][j];
            cout<<endl;
        }
    }
    return 0;
}
