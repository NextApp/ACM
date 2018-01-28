#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100
using namespace std;
int a[N],b[N],d[N][N],n,A[N],vis[N];
int main()
{
  //  freopen("1.txt","r",stdin);
    cin>>n;
    int e;
    for(int i=1; i<=n; i++)
    {
        cin>>e;
        a[e-1]=i;
    }
    while(cin>>e)
    {
        b[e-1]=1;
        for(int j=1; j<n; j++)
        {
            cin>>e;
            b[e-1]=j+1;
        }
        for(int i=n; i>=0; i--)
            for(int j=n; j>=0; j--)
            {
                if(i==n||j==n)d[i][j]=0;
                else if(a[i]==b[j])d[i][j]=d[i+1][j+1]+1;
                else d[i][j]=max(d[i][j+1],d[i+1][j]);
            }
        cout<<d[0][0]<<endl;
    }
    return 0;
}
