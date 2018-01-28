#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char M[30][30];
int ix[]= {-1,-1,-1,0,0,1,1,1};
int iy[]= {-1,0,1,-1,1,-1,0,1};
int dfs(int i,int j)
{
    M[i][j]='0';
    for(int t=0; t<8; t++)
    {
        int dx=i+ix[t],dy=j+iy[t];
        if(dx>=0&&dx<n&&dy>=0&&dy<n&&M[dx][dy]=='1')
            dfs(dx,dy);
    }
}
int main()
{
    int id=1;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            cin>>M[i];
        int num=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(M[i][j]=='1')
                {
                    dfs(i,j);
                    num++;
                }
        cout<<"Image number "<<id++<<" contains "<<num<<" war eagles."<<endl;
    }
    return 0;
}
