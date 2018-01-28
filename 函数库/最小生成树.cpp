#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100
#define MAX 1000000
using namespace std;
int M[N][N],n,ss=0,S[N];
struct G
{
    int ix,iy;
}q[N*N],p[N];
int cmp(const void *_a,const void *_b)
{
    G*a=(G*)_a;
    G*b=(G*)_b;
    return  M[b->ix][b->iy] - M[a->ix][a->iy];
}
void read()
{
    int a,b,l,m;
    memset(M,0,sizeof(M));
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>a>>b>>l;
        M[a][b]=l;
        M[b][a]=l;
    }
}
void  MiniSpanTree_PRIM(int u)
{
    int ix,min=MAX,mm=0,k=1;
    S[k-1]=u;
    while(k<n)
    {
        for (int i=0;i<n;i++)
        {
            if (M[u][i])
            {
                q[mm].ix=u,q[mm].iy=i;
                mm++;
            }
        }
        qsort(q,mm,sizeof(G),cmp);
        while(mm&&!M[q[mm-1].ix][q[mm-1].iy])mm--;
        int m=q[mm-1].iy;
        p[ss].ix=q[mm-1].ix,p[ss++].iy=m;
        u=m;
        for(int i=0;i<k;i++)M[S[i]][m]=0,M[m][S[i]]=0;
        S[k]=u;
        k++;
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    read();
    MiniSpanTree_PRIM(0);
    for(int i=0;i<ss;i++)
    {
        cout<<p[i].ix<<' '<<p[i].iy<<endl;
    }
}
