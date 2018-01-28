#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char M[20];
int mm=0;
int dfs(int move)
{
    if(move>mm)mm=move;
    for(int i=0;i<10;i++)
    if(M[i]=='o'&&M[i+1]=='o'&&M[i+2]=='-')
    {
        M[i+2]='o',M[i]=M[i+1]='-';
        dfs(move+1);
        M[i+2]='-',M[i]=M[i+1]='o';
    }
    for(int i=11;i>=2;i--)
    if(M[i]=='o'&&M[i-1]=='o'&&M[i-2]=='-'){
        M[i-2]='o',M[i]=M[i-1]='-';
        dfs(move+1);
        M[i-2]='-',M[i]=M[i-1]='o';
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>M;
        int num=0;
        for(int i=0;M[i];i++)
        if(M[i]=='o')num++;
        mm=0;
        dfs(0);
        cout<<num-mm<<endl;
    }
    return 0;
}
