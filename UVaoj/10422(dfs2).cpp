#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char M[6][6],S[6][6];
int dx[]= {-2,-2,2,2,-1,1,-1,1},dy[]= {-1,1,-1,1,-2,-2,2,2};
int Min,mu,ok;
int diff()
{
    int s=0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(M[i][j]!=S[i][j])
                s++;
    return s/2;
}
int dfs(int x,int y,int move)
{
    if(diff()+move>mu)return 0;
    else
    {
        if(memcmp(M,S,sizeof(M))==0)
        {
            ok=1;Min=move;
            return 0;
        }
        for(int i=0; i<8; i++)
        {
            int nx=dx[i]+x,ny=dy[i]+y;
            if(nx>=0&&ny>=0&&nx<5&&ny<5)
            {
                M[x][y]=M[nx][ny];
                M[nx][ny]=' ';
                dfs(nx,ny,move+1);
                M[nx][ny]=M[x][y];
                M[x][y]=' ';
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    strcpy(S[0],"11111");
    strcpy(S[1],"01111");
    strcpy(S[2],"00 11");
    strcpy(S[3],"00001");
    strcpy(S[4],"00000");
    int n;
    cin>>n;
    getchar();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
            gets(M[j]);
        Min=12,ok=0;
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                if(M[j][k]==' ')
                {
                    for(int t=1; t<11&&!ok; t++)
                    {
                        mu=t;
                        dfs(j,k,0);
                    }
                }
        if(Min<12)cout<<"Solvable in "<<Min<<" move(s)."<<endl;
        else cout<<"Unsolvable in less than 11 move(s)."<<endl;
    }
    return 0;
}
