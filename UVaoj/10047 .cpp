#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int M[30][30][6][4];
char S[30][30];
int ix[4]={-1,0,1,0},a,b;
int iy[4]={0,1,0,-1};
int q1[20000],q2[20000],q3[20000],q4[20000];
int bfs(int i,int j)
{
    int rear=1,front=0;
    q1[0]=i,q2[0]=j,q3[0]=1,q4[0]=0;
    M[i][j][1][0]=1;
    int mm=0;
    while(front<rear)
    {
        int u=q1[front];
        int m=q2[front];
        int c=q3[front];
        int f=q4[front++];
        int dx,dy,F,C;
        for(int o=-1;o<2;o+=1)
        {
            if(!o)dx=u+ix[f],dy=m+iy[f];
            else dx=u,dy=m;
            F=f+o;
            if(!o)C=c==5?1:c+1;
            else C=c;
            if(F>3)F=0;
            else if(F<0)F=3;
            if(dx>=0&&dy>=0&&dx<a&&dy<b&&S[dx][dy]!='#'&&!M[dx][dy][C][F])
                {
                    if(S[dx][dy]=='T'&&C==1)
                    return M[u][m][c][f];
                    M[dx][dy][C][F]=M[u][m][c][f]+1;
                    q1[rear]=dx;
                    q2[rear]=dy;
                    q3[rear]=C;
                    q4[rear++]=F;
                }
        }
    }
    return 0;
}
int main()
{
    int id=1;
    //freopen("1.txt","r",stdin);
    while(cin>>a>>b)
    {
        if(!a&&!b)return 0;
        else
        {
            memset(M,0,sizeof(M));
            if(id!=1)cout<<endl;
            for(int i=0;i<a;i++)
            cin>>S[i];
            int min=0;
            for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                if(S[i][j]=='S')
                min=bfs(i,j);
            }
            cout<<"Case #"<<id++<<endl;
            if(min)
            cout<<"minimum time = "<<min<<" sec"<<endl;
            else
            cout<<"destination not reachable"<<endl;
        }
    }
    return 0;
}
