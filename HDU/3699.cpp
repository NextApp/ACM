#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n,vis[200],C[200],sum,M[20],lena,lenb,lenc;
char a[20],b[20],c[20];
void dfs(int cur)
{
    if(cur==n)
    {
        int aa=0,bb=0,cc=0;
        for(int i=0; a[i]; i++)
            aa=10*aa+C[vis[a[i]]];
        for(int j=0; b[j]; j++)
            bb=10*bb+C[vis[b[j]]];
        for(int j=0; c[j]; j++)
            cc=10*cc+C[vis[c[j]]];
            int ok=0;
        if(lena>1&&C[vis[a[0]]]==0)return;
        if(lenb>1&&C[vis[b[0]]]==0)return;
        if(lenc>1&&C[vis[c[0]]]==0)return;
        if(aa+bb==cc)sum++,ok=1;
        if(aa*bb==cc)sum++,ok=1;
        if(bb&&aa%bb==0&&aa/bb==cc)sum++,ok=1;
        if(aa-bb==cc)sum++,ok=1;
    }
    else for(int i=0; i<10; i++)
        {
            if(!M[i])
            {
                C[cur]=i;
                M[i]=1;
                dfs(cur+1);
                M[i]=0;
            }
        }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s%s",a,b,c);
        memset(vis,0,sizeof(vis));
        memset(M,0,sizeof(M));
        lena=strlen(a),lenb=strlen(b),lenc=strlen(c);
        for(int i=0; a[i]; i++)
            vis[a[i]]=1;
        for(int i=0; b[i]; i++)
            vis[b[i]]=1;
        for(int i=0; c[i]; i++)
            vis[c[i]]=1;
        n=0;
        sum=0;
        for(int i='A'; i<='E'; i++)
            if(vis[i])vis[i]=n++;
        dfs(0);
        printf("%d\n",sum);
    }
    return 0;
}
