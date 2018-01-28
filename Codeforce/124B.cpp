#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define N 120
using namespace std;
int m,n,a[N],b[N];
int main()
{
    // freopen("1.txt","r",stdin);
    while(cin>>n>>m)
    {
        for(int i=0; i<=n; i++)
            cin>>a[i];
        for(int j=0; j<=m; j++)
            cin>>b[j];
        if(n==m)
        {
            for(int i=100; i>=2; i--)
                if(a[0]%i==0&&b[0]%i==0)
                {
                    a[0]/=i,b[0]/=i;
                    break;
                }
            if(a[0]>0&&b[0]<0)cout<<-a[0]<<'/'<<-b[0]<<endl;
            else if(a[0]<0&&b[0]<0)cout<<-a[0]<<'/'<<-b[0]<<endl;
            else cout<<a[0]<<'/'<<b[0]<<endl;
        }
        else if(n>m)
        {
            if((a[0]<0&&b[0]>0)||(a[0]>0&&b[0]<0))cout<<"-Infinity"<<endl;
            else cout<<"Infinity"<<endl;
        }
        else
        {
            cout<<"0/1"<<endl;
        }
    }
    return 0;
}
