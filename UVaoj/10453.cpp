#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;
int d[N][N];
char a[N];
int dp(int i,int j)
{
    if(j<=i)return d[i][j]=0;
    if(d[i][j]!=-1)return d[i][j];
    if(a[i]==a[j])return d[i][j]=dp(i+1,j-1);
    else return d[i][j]=min(dp(i,j-1),dp(i+1,j))+1;
}
void dfs(int i,int j)
{
    if(j==i)
    {
        printf("%c",a[i]);
        return ;
    }
    else if(j<i)
    {
        return ;
    }
    if(a[i]==a[j])
    {
        if(d[i][j]==d[i+1][j-1])
        {
            printf("%c",a[i]);
            dfs(i+1,j-1);
            printf("%c",a[i]);
        }
    }
    else
    {
        if(d[i][j]==d[i+1][j]+1)
        {
            printf("%c",a[i]);
            dfs(i+1,j);
            printf("%c",a[i]);
        }
        else if(d[i][j]==d[i][j-1]+1)
        {
            printf("%c",a[j]);
            dfs(i,j-1);
            printf("%c",a[j]);
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(~scanf("%s",&a))
    {
        int len=strlen(a);
        memset(d,-1,sizeof(d));
        dp(0,len-1);
        printf("%d ",d[0][len-1]);
        dfs(0,len-1);
        printf("\n");
    }
    return 0;
}
