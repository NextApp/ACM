#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,M[100][100],OK,N[100][100],ix,iy;
char a[100][100];
int dfs(int i,int j,int ok,int t,int d)
{

    if(ix==i&&ok&&iy==j&&d>2)
    {
        OK=t-2;
    }
    else if(!OK&&((!ok&&!M[i][j])||(ok&&!N[i][j])))
    {
        if(!ok)
        {
            M[i][j]=1;
            if(i-1>=0&&a[i][j]==a[i-1][j]&&a[i-1][j]=='/')N[i-1][j]=1;
            if(i+1<m&&a[i][j]==a[i+1][j]&&a[i+1][j]==92)N[i+1][j]=1;
            if(j-1>=0&&a[i][j]==a[i][j-1])N[i][j-1]=1;
        }
        else
        {
            N[i][j]=1;
            if(i-1>=0&&a[i][j]==a[i-1][j]&&a[i-1][j]==92)M[i-1][j]=1;
            if(i+1<m&&a[i+1][j]==a[i][j]&&a[i+1][j]=='/')M[i+1][j]=1;
            if(j+1<n&&a[i][j]==a[i][j+1])M[i][j+1]=1;
        }
        if(!ok)
        {
            if(a[i][j]=='/')
            {
                if(j-1>=0&&a[i][j-1]==92)dfs(i,j-1,1,t+1,d+1);
                else if(i+1<m&&j-1>=0)
                {
                    if(a[i+1][j-1]=='/')dfs(i+1,j-1,0,t+2,d+1);
                    else if(a[i+1][j]==92)dfs(i+1,j,0,t+3,d+1);
                    else dfs(i,j,1,t+4,d+1);
                }
                if(i-1>=0&&a[i-1][j]==92)dfs(i-1,j,0,t+1,d+1);
                else if(i-1>=0&&j+1<n)
                {
                    if(a[i][j]=='/')dfs(i-1,j+1,0,t+2,d+1);
                    else if(a[i][j+1]==92)dfs(i,j+1,1,t+3,d+1);
                    else dfs(i,j,1,t+4,d+1);
                }
            }
            else if(a[i][j]==92)
            {
                if(i+1<m&&a[i+1][j]=='/')dfs(i+1,j,0,t+1,d+1);
                else if(i+1<m&&j+1<n)
                {
                    if(a[i+1][j+1]==92)dfs(i+1,j+1,0,t+2,d+1);
                    else if(a[i][j+1]=='/')dfs(i,j+1,1,t+3,d+1);
                    else dfs(i,j,1,t+4,d+1);
                }
                if(j-1>=0&&a[i][j-1]=='/')dfs(i,j-1,1,t+1,d+1);
                else if(i-1>=0&&j-1>=0)
                {
                    if(a[i-1][j-1]==92)dfs(i-1,j-1,0,t+2,d+1);
                    else if(a[i-1][j]=='/')dfs(i-1,j,0,t+3,d+1);
                    else dfs(i,j,1,t+4,d+1);
                }
            }
        }
        else
        {
            if(a[i][j]=='/')
            {
                if(j+1<n&&a[i][j+1]==92)dfs(i,j+1,0,t+1,d+1);
                else if(i-1>=0&&j+1<n)
                {
                    if(a[i-1][j+1]=='/')dfs(i-1,j+1,1,t+2,d+1);
                    else if(a[i-1][j]==92)dfs(i-1,j,1,t+3,d+1);
                    else dfs(i,j,0,t+4,d+1);
                }
                if(i+1<m&&a[i+1][j]==92)dfs(i+1,j,1,t+1,d+1);
                else if(i+1<m&&j-1>=0)
                {
                    if(a[i+1][j-1]=='/')dfs(i+1,j-1,1,t+2,d+1);
                    else if(a[i][j-1]==92)dfs(i,j-1,0,t+3,d+1);
                    else dfs(i,j,0,t+4,d+1);
                }
            }
            else if(a[i][j]==92)
            {
                if(j+1<n&&a[i][j+1]=='/')dfs(i,j+1,0,t+1,d+1);
                else if(i+1<m&&j+1<n)
                {
                    if(a[i+1][j+1]==92)dfs(i+1,j+1,1,t+2,d+1);
                    else if(a[i+1][j]=='/')dfs(i+1,j,1,t+3,d+1);
                    else dfs(i,j,0,t+4,d+1);
                }
                if(i-1>=0&&a[i-1][j]=='/')dfs(i-1,j,1,t+1,d+1);
                else if(i-1>=0&&j-1>=0)
                {
                    if(a[i-1][j-1]==92)dfs(i-1,j-1,1,t+2,d+1);
                    else if(a[i][j-1]='/')dfs(i,j-1,0,t+3,d+1);
                    else dfs(i-1,j-1,0,t+4,d+1);
                }
            }
        }
    }
}
int main()
{
    freopen("2.txt","r",stdin);
    int id=1;
    while(cin>>n>>m)
    {
        if(!m&&!n)break;
        else
        {
            memset(M,0,sizeof(M));
            memset(N,0,sizeof(N));
            for(int i=0; i<m; i++)cin>>a[i];
            int sum=0,max=0;
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                {
                    int t=2;
                    ix=i,iy=j;
                    OK=0;
                    if(!N[i][j])dfs(i,j,1,t,0);
                    if(OK)
                    {
                        sum++;
                        max=max>OK?max:OK;
                    }
                }
            cout<<"Maze #"<<id++<<":"<<endl;
            if(sum)cout<<sum<<" Cycles; the longest has length "<<max<<"."<<endl<<endl;
            else cout<<"There are no cycles."<<endl<<endl;
        }
    }
    return 0;
}
