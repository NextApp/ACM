#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 10000000
using namespace std;
int v,n,a[100]= {0},d[100][100];
int dp(int i,int j)
{
    if(j-i<=1)return 0;
    if(d[i][j]>=0)return d[i][j];
    int mm=INF;
    for(int t=i+1; t<j; t++)
        mm=min(dp(i,t)+dp(t,j)+a[j]-a[i],mm);
    return d[i][j]=mm;
}
int main()
{
  //  freopen("1.txt","r",stdin);
    while(cin>>v)
    {
        if(!v)break;
        else
        {
            cin>>n;
            for(int i=1; i<=n; i++)
                cin>>a[i];
            memset(d,-1,sizeof(d));
            a[n+1]=v;
            cout<<"The minimum cutting is "<<dp(0,n+1)<<"."<<endl;
        }
    }
    return 0;
}
