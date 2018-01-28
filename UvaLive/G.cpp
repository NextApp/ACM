#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char M[10][10];
int SSS(int x,int y)
{
    if(x-1>=0&&x+1<5&&M[x+1][y]==M[x][y]&&M[x-1][y]==M[x][y])return 1;
    else if(x+1<5&&y+1<5&&y-1>=0&&x-1>=0&&M[x+1][y+1]==M[x][y]&&M[x-1][y-1]==M[x][y])return 1;
    else if(y+1<5&&y-1>=0&&M[x][y]==M[x][y+1]&&M[x][y]==M[x][y-1])return 1;
    else if(x-1>=0&&y+1<5&&x+1<5&&y-1>=0&&M[x-1][y+1]==M[x][y]&&M[x][y]==M[x+1][y-1])return 1;
    else return 0;

}
int main()
{
   //freopen("1.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int ok1=0,ok2=0;
        for(int j=0;j<5;j++)cin>>M[j];
        for(int j=0;j<5;j++)
        for(int s=0;s<5;s++)
        {
            if(M[j][s]=='A'&&SSS(j,s))ok1=1;
            else if(M[j][s]=='B'&&SSS(j,s))ok2=1;
        }
        if(ok1==ok2)cout<<"draw"<<endl;
        else if(ok1)cout<<"A wins"<<endl;
        else cout<<"B wins"<<endl;
    }
    return 0;
}
