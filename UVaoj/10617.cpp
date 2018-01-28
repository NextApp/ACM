#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char m[100];
long long d[100][100];
long long dp(int i,int j)
{
    if(i==j)return d[i][j]=1;
    else if(j<i)return 0;
    else if(d[i][j])return d[i][j];
    else
    {
        if(m[i]==m[j])d[i][j]=dp(i,j-1)+dp(i+1,j)+1;
        else d[i][j]=dp(i,j-1)+dp(i+1,j)-dp(i+1,j-1);
    }
    return d[i][j];
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        memset(d,0,sizeof(d));
        cin>>m;
        int len=strlen(m);
        dp(0,len-1);
        cout<<d[0][len-1]<<endl;
    }
    return 0;
}
