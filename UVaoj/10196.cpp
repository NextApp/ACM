#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char M[10][10];
char king;
int judge()
{
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(M[i][j]!='.')return 0;
    return 1;
}
int Pawn(int i,int j)
{
    if(i<7&&j>0&&M[i+1][j-1]==king)return 1;
    if(i<7&&j<7&&M[i+1][j+1]==king)return 1;
    return 0;
}
int Pawn1(int i,int j)
{
    if(i>0&&j>0&&M[i-1][j-1]==king)return 1;
    if(i>0&&j<7&&M[i-1][j+1]==king)return 1;
    return 0;
}
int Rook(int i,int j)
{
    int x=i,y=j;
    while(--x>=0)
    {
        if(M[x][j]!='.')
        {
            if(M[x][j]==king)return 1;
            break;
        }
    }
    x=i;
    while(++x<8)
    {
        if(M[x][j]!='.')
        {
            if(M[x][j]==king)return 1;
            break;
        }
    }
    while(--y>=0)
    {
        if(M[i][y]!='.')
        {
            if(M[i][y]==king)return 1;
            break;
        }
    }
    y=j;
    while(++y<8)
    {
        if(M[i][y]!='.')
        {
            if(M[i][y]==king)return 1;
            break;
        }
    }
    return 0;
}
int Bishop(int i,int j)
{
    int x=i,y=j;
    while(--x>=0&&--y>=0)
    {
        if(M[x][y]!='.')
        {
            if(M[x][y]==king)
                return 1;
            break;
        }
    }
    x=i,y=j;
    while(++x<8&&--y>=0)
    {
        if(M[x][y]!='.')
        {
            if(M[x][y]==king)return 1;
            break;
        }
    }
    x=i,y=j;
    while(++x<8&&++y<8)
    {
        if(M[x][y]!='.')
        {
            if(M[x][y]==king)return 1;
            break;
        }
    }
    x=i,y=j;
    while(--x>=0&&++y<8)
    {
        if(M[x][y]!='.')
        {
            if(M[x][y]==king)return 1;
            break;
        }
    }
    return 0;
}
int dx[]= {-1,-1,-1,0,1,1,1,0};
int dy[]= {-1,0,1,1,1,0,-1,-1};
int King(int i,int j)
{
    for(int t=0; t<8; t++)
    {
        int x=dx[t]+i,y=dy[t]+j;
        if(x>=0&&y>=0&&x<8&&y<8&&M[x][y]==king)return 1;
    }
    return 0;
}
int wx[]= {-2,-2,-1,1,2,2,1,-1};
int wy[]= {-1,1,2,2,1,-1,-2,-2};
int Knight(int i,int j)
{
    for(int t=0; t<8; t++)
    {
        int x=i+wx[t],y=j+wy[t];
        if(x>=0&&x<8&&y>=0&&y<8&&M[x][y]==king)return 1;
    }
    return 0;
}
int check1()
{
    king='K';
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            switch(M[i][j])
            {
            case 'p':
                if(Pawn(i,j))return 1;
                break;
            case 'r':
                if(Rook(i,j))return 1;
                break;
            case 'b':
                if(Bishop(i,j))return 1;
                break;
            case 'q':
                if(Rook(i,j)||Bishop(i,j))return 1;
                break;
            case 'k':
                if(King(i,j))return 1;
                break;
            case 'n':
                if(Knight(i,j))return 1;
                break;
            default:
                break;
            }
    return 0;
}
int check2()
{
    king='k';
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            switch(M[i][j])
            {
            case 'P':
                if(Pawn1(i,j))return 1;
                break;
            case 'R':
                if(Rook(i,j))return 1;
                break;
            case 'B':
                if(Bishop(i,j))return 1;
                break;
            case 'Q':
                if(Rook(i,j)||Bishop(i,j))return 1;
                break;
            case 'K':
                if(King(i,j))return 1;
                break;
            case 'N':
                if(Knight(i,j))return 1;
                break;
            default:
                break;
            }
    return 0;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int id=1;
    while(1)
    {
        for(int i=0; i<8; i++)
            scanf("%s",M[i]);
        if(judge())break;
        printf("Game #%d:",id++);
        if(check1())printf(" white king is in check.\n");
        else if(check2())printf(" black king is in check.\n");
        else printf(" no king is in check.\n");
    }
    return 0;
}
