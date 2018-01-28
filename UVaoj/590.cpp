#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
long long d[20][1100],M[20][20][40];
void dp()
{
    d[0][0]=0;
    for(int kk=0; kk<k; kk++)
        for(int nn=0; nn<n; nn++)
            for(int i=0; i<n; i++)
                if(nn!=i)
                {
                    int day=M[nn][i][0];
                    day=(kk+1)%day==0?day:(kk+1)%day;
                    if(d[nn][kk]!=-1&&M[nn][i][day])
                    {
                        if(d[i][kk+1]==-1)d[i][kk+1]=d[nn][kk]+M[nn][i][day];
                        else d[i][kk+1]=min(d[i][kk+1],d[nn][kk]+M[nn][i][day]);
                    }
                }
    if(d[n-1][k]!=-1)cout<<"The best flight costs "<<d[n-1][k]<<"."<<endl;
    else cout<<"No flight possible."<<endl;
    cout<<endl;
}
int main()
{
    freopen("1.txt","r",stdin);
    int id=0;
    while(cin>>n>>k)
    {
        if(!n&&!k)return 0;
        else
        {
            cout<<"Scenario #"<<++id<<endl;
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(i!=j)
                    {
                        cin>>M[i][j][0];
                        for(int t=1; t<=M[i][j][0]; t++)
                            cin>>M[i][j][t];
                    }
            memset(d,-1,sizeof(d));
            dp();
        }
    }
    return 0;
}
