#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100];
int x,y,b[120][120],d[120][120];
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int dp(int i,int j)
{
    if(d[i][j]>=0)return d[i][j];
    int mm=1;
    for(int t=0; t<4; t++)
    {
        int m=dx[t]+i,n=dy[t]+j;
        if(m>=0&&n>=0&&m<x&&n<y&&b[m][n]<b[i][j])
        mm=max(mm,dp(m,n)+1);
    }
    return d[i][j]=mm;
}
int main()
{
    int n;
    //freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>x>>y;
        memset(d,-1,sizeof(d));
        for(int j=0; j<x; j++)
            for(int k=0; k<y; k++)
                cin>>b[j][k];
        int mm=0;
        for(int j=0; j<x; j++)
            for(int k=0; k<y; k++)
                if(d[j][k]<0)
                    mm=max(mm,dp(j,k));
        cout<<a<<": "<<mm<<endl;
    }
    return 0;
}
