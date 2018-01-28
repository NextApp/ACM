#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char M[120][200];
char S[900][100],name[800][100];
int sum,n,vis[120];
int cmp(const void *_a,const void *_b)
{
    char *a=(char*)_a;
    char *b=(char*)_b;
    return strcmp(a,b);
}
void insert(char a[])
{
    for(int i=0; i<sum; i++)
        if(!strcmp(a,S[i]))return ;
    strcpy(S[sum++],a);
}
int b_search(char m[])
{
    int first=1,end=n-1;
    while(first<=end)
    {
        int k=(first+end)/2;
        int s=strcmp(m,name[k]);
        if(!s)return k;
        else if(s<0)end=k-1;
        else first=k+1;
    }
    return -1;
}
int dfs(char a[])
{
    int m=b_search(a);
    if(m==-1)insert(a);
    else if(!vis[m])
    {
        vis[m]=1;
        char b[100];
        int j=0,i=0;
        while(M[m][i])
        {
            if(M[m][i]==','||M[m][i]=='.')
            {
                b[j]='\0';
                dfs(b);
                j=0;
            }
            else b[j++]=M[m][i];
            i++;
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%s",M[i]);
        qsort(M+1,n-1,sizeof(M[0]),cmp);
        for(int i=1,j; i<n; i++)
        {
            for(j=0; M[i][j]&&M[i][j]!=':'; j++)
                name[i][j]=M[i][j];
            name[i][j]='\0';
            strcpy(M[i],M[i]+j+1);
        }
        memset(vis,0,sizeof(vis));
        int ok=0;
        sum=0;
        for(int i=0; M[0][i]; i++)
        {
            if(M[0][i]==':')ok=1,i++;
            if(ok)
            {
                char b[100];
                int j=0;
                while(M[0][i])
                {
                    if(M[0][i]==','||M[0][i]=='.')
                    {
                        b[j]='\0';
                        dfs(b);
                        j=0;
                    }
                    else b[j++]=M[0][i];
                    i++;
                }
                break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
