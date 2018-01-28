#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char M[200][200];
int m,n,F[2000][3],S[2000][3];
int ddd(int ai,int aj,int bi,int bj,char c)
{
    int ok=1;
    for(int i=ai;i<=bi;i++)
    if(M[i][aj]!=c||M[i][bj]!=c)ok=0;
    for(int j=aj;j<=bj;j++)
    if(M[ai][j]!=c||M[bi][j]!=c)ok=0;
    for(int i=ai+1;i<bi;i++)
    for(int j=aj+1;j<bj;j++)
    if(M[i][j]!='.')ok=0;
    return ok;
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        if(!m&&!n)break;
        else
        {
            for(int i=0; i<m; i++)
                cin>>M[i];
            int k=0,t=0,o=0;
            char N[1000];
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                {
                    if(M[i][j]>'Z'||M[i][j]<'A')continue;
                    if(j+1<n&&i+1<m&&M[i][j]==M[i][j+1]&&M[i][j]==M[i+1][j])
                    F[k][0]=i,F[k++][1]=j;
                    else if(i-1>=0&&j-1>=0&&M[i][j]==M[i-1][j]&&M[i][j]==M[i][j-1])
                    S[t][0]=i,S[t++][1]=j;
                }
            for(int i=0;i<k;i++)
            for(int j=0;j<t;j++)
            {
                if(F[i][0]<S[j][0]-1&&F[i][1]<S[j][1]-1&&M[F[i][0]][F[i][1]]==M[S[j][0]][S[j][1]])
                {
                    if(ddd(F[i][0],F[i][1],S[j][0],S[j][1],M[S[j][0]][S[j][1]]))
                    N[o++]=M[S[j][0]][S[j][1]];
                }
            }
            sort(N,N+o);
            for(int i=0;i<o;i++)cout<<N[i];
            cout<<endl;
        }
    }
    return 0;
}
