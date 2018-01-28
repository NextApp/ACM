#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 10000000
#define N 25
using namespace std;
int d[N][N],M[N][N],nm;
int main()
{
    int id=1;
    //freopen("1.txt","r",stdin);
    while(cin>>nm)
    {
        int m;
        memset(M,0,sizeof(M));
        for(int i=0; i<nm; i++)
        {
            cin>>m;
            M[1][m]=M[m][1]=1;
        }
        for(int i=2; i<20; i++)
        {
            cin>>nm;
            for(int j=0; j<nm; j++)
            {
                cin>>m;
                M[i][m]=1;
            }
        }
        for(int i=1; i<=20; i++)
        {
            d[i][i]=0;
            for(int j=i+1; j<=20; j++)
                if(!M[i][j])d[j][i]=d[i][j]=INF;
                else d[i][j]=d[j][i]=1;
        }
        for(int i=1; i<=20; i++)
            for(int j=1; j<=20; j++)
                for(int k=1; k<=20; k++)
                d[j][k]=min(d[j][i]+d[i][k],d[j][k]);
        int n;
        cin>>n;
        printf("Test Set #%d\n",id++);
        for(int i=0; i<n; i++)
        {
            int s,e;
            cin>>s>>e;
            printf("%2d to %2d: %d\n",s,e,d[s][e]);
        }
        cout<<endl;
    }
    return 0;
}
