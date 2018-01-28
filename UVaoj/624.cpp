#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,a[30],d[30][10100],p[30][10100];
void print(int cur,int j)
{
    if(cur==0)return ;
    print(cur-1,p[cur][j]);
    if(p[cur][j]<j)
        cout<<a[cur]<<' ';
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>n>>m)
    {
        for(int i=1; i<=m; i++)
            cin>>a[i];
        for(int i=1; i<=m; i++)
            for(int j=0; j<=n; j++)
            {
                d[i][j]=(i==1)?0:d[i-1][j];
                p[i][j]=j;
                if(j>=a[i])
                {
                    int s=d[i-1][j-a[i]]+a[i];
                    if(d[i][j]<s)
                    {
                        d[i][j]=s;
                        p[i][j]=j-a[i];
                    }
                }
            }
   /*   for(int i=1; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
                cout<<d[i][j]<<' ';
            cout<<endl;
            for(int j=0; j<=n; j++)
                cout<<p[i][j]<<' ';
                cout<<endl<<endl;;
        }*/
        cout<<endl;
        print(m,n);
        cout<<endl;
        cout<<"sum:"<<d[m][n]<<endl;
    }
    return 0;
}
