#include<iostream>
#include<cstring>
#include<cstdio>
#define N 1020
using namespace std;
char a[N],b[N];
int lena,lenb,d[N][N];
int dp(int i,int j)
{
    if(i>=lena||j>=lenb)return 0;
    if(d[i][j]>=0)return d[i][j];
    if(a[i]==b[j])return dp(i+1,j+1)+1;
    return d[i][j]=max(dp(i+1,j),dp(i,j+1));
}
int main()
{
    while(gets(a)!=NULL)
    {
        gets(b);
        memset(d,-1,sizeof(d));
        lena=strlen(a),lenb=strlen(b);
        cout<<dp(0,0)<<endl;
    }
    return 0;
}
