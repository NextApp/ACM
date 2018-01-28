#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,M[100][100],OK,N[100][100],ix,iy;
char a[100][100];
int dx[]= {-1,-1,0,0,0,1,1,0, 0,-1,-1,0,1,1,0,0, 0,-1,-1,0,1,1,0,0, -1,-1,0,0,0,1,1,0};
int dy[]= {0,1,1,0,-1,-1,0,0, 1,1,0,0,0,-1,-1,0, -1,-1,0,0,0,1,1,0, 0,-1,-1,0,1,1,0,0};
int ox[]= {0,0,1,1,1,0,0,1,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,1,1,0};
char b[40];
int dfs(int i,int j,int ok,int t,int d)
{
    if(ix==i&&ok&&iy==j&&d>2)OK=t;
    else if(!OK&&((!ok&&!M[i][j])||(ok&&!N[i][j])))
    {
        if(!ok)
        {
            M[i][j]=1;
            if(j-1>=0&&a[i][j]==a[i][j-1])N[i][j-1]=1;
        }
        else
        {
            N[i][j]=1;
            if(j+1<n&&a[i][j]==a[i][j+1])M[i][j+1]=1;
        }
        int c=0,k=0;
        if(ok)c=8;
        if(a[i][j]==92)k=16;
        for(int o=c+k; o<8+c+k; o++)
        {
            int x=dx[o]+i,y=dy[o]+j;
            int cx=x,cy=y;
            if(o%4>1)cx=dx[o-o%4+1]+i,cy=dy[o-o%4+1]+j;
            if(cx>=0&&cy>=0&&cx<m&&cy<n&&a[x][y]==b[o])
            {
                dfs(x,y,ox[o],t+o%4+1,d+1);
                o=(o/4+1)*4-1;
            }
        }
    }
}
int main()
{
    //freopen("2.txt","r",stdin);
    int id=1;
    for(int i=0; i<16; i+=2)
        b[i]=92,b[i+1]='/';
    for(int i=16; i<32; i+=2)
        b[i]='/',b[i+1]=92;
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
                    ix=i,iy=j;
                    if(!N[i][j])
                    {
                        OK=0;
                        dfs(i,j,1,0,0);
                        if(OK)
                        {
                            sum++;
                            max=max>OK?max:OK;
                        }
                    }
                }
            cout<<"Maze #"<<id++<<":"<<endl;
            if(sum)cout<<sum<<" Cycles; the longest has length "<<max<<"."<<endl<<endl;
            else cout<<"There are no cycles."<<endl<<endl;
        }
    }
    return 0;
}
