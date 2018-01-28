#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[100][100];
int dp(int m,int n)
{
    if(!m)return d[m][n]=1;
    if(d[m][n]>=0)return d[m][n];
    int sum=0;
    for(int i=0;i<=n;i++)
    sum+=dp(m-1,i);
    return d[m][n]=sum;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(d,-1,sizeof(d));
        int a,b,c;
        cin>>a>>b>>c;
        if(b-a*c<0)cout<<0<<endl;
        else if(a==0)cout<<0<<endl;
        else
        cout<<dp(b-a*c,a-1)<<endl;
    }
    return 0;
}
