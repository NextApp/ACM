#include<iostream>
#include<cstdio>
#include<cstring>
#define INF (1<<31)-1
using namespace std;
int m,n,M[12][120],d[12][120];
char l[12][120][120];
int dx[]= {-1,0,1};
int dp(int i,int j,char c[])
{
    if(j>=n)return 0;
    c[j]=i+1;
    if(d[i][j]<INF)
    {
        strcpy(c+j,l[i][j]);
        return d[i][j];
    }
    char s[120];
    int mm=INF;
    for(int t=0; t<3; t++)
    {
        int ix=dx[t]+i;
        ix=ix<0?m+ix:ix;
        int o=dp(ix%m,j+1,c)+M[i][j];
        if(mm>=o)
        {
            if(mm>o||strcmp(s+j,c+j)>0)strcpy(s+j,c+j);
            mm=o;
        }
    }
    strcpy(l[i][j],s+j);
    strcpy(c+j,s+j);
    return d[i][j]=mm;
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                cin>>M[i][j];
                d[i][j]=INF;
            }
        int mm=INF;
        char c[120],s[120];
        c[n]='\0';
        for(int i=0; i<m; i++)
        {
            int o=dp(i,0,c);
            if(mm>=o)
            {
                if(o<mm||strcmp(s,c)>0)strcpy(s,c);
                mm=o;
            }
        }
        for(int i=0; i<n-1; i++)
            cout<<(int)s[i]<<' ';
        cout<<(int)s[n-1]<<endl<<mm<<endl;
    }
    return 0;
}
