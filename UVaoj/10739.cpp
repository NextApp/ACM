#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1200
using namespace std;
char a[N];
int d[N][N];
int dp(int i,int j)
{
    if(j==i)return 0;
    else if(d[i][j]!=N)return d[i][j];
    else
    {
        if(a[i]==a[j])
        {
            if(j-i-2>=0)d[i][j]=dp(i+1,j-1);
            else d[i][j]=0;
        }
        else
        {
            if(j-i-2>=0)d[i][j]=min(d[i][j],dp(i+1,j-1)+1);
            else d[i][j]=min(d[i][j],1);
            if(j-i>=1)
            {
                d[i][j]=min(d[i][j],dp(i,j-1)+1);
                d[i][j]=min(d[i][j],dp(i+1,j)+1);
            }
            else d[i][j]=min(d[i][j],1);
        }
    }
    return d[i][j];
}
int main()
{
    int T,id=1;
   // freopen("1.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>a;
        int len=strlen(a);
        for(int i=0; i<len; i++)
            for(int j=i; j<len; j++)
                if(j==i)d[i][j]=0;
                else d[i][j]=N;
        dp(0,len-1);
        cout<<"Case "<<id++<<": "<<d[0][len-1]<<endl;
    }
    return 0;
}
