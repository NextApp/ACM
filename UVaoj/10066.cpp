#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[120],b[120],d[120][120];
int main()
{
   // freopen("1.txt","r",stdin);
    int m,n,id=1;
    while(cin>>n>>m)
    {
        if(!m&&!n)break;
        else
        {
            for(int i=0; i<n; i++)cin>>a[i];
            for(int j=0; j<m; j++)
                cin>>b[j];
            for(int i=n; i>=0; i--)
                for(int j=m; j>=0; j--)
                {
                    if(i==n||j==m)d[i][j]=0;
                    else if(a[i]==b[j])d[i][j]=d[i+1][j+1]+1;
                    else d[i][j]=max(d[i][j+1],d[i+1][j]);
                }
                cout<<"Twin Towers #"<<id++<<endl;
            cout<<"Number of Tiles : "<<d[0][0]<<endl<<endl;
        }
    }
    return 0;
}
