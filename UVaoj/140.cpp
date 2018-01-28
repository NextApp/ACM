#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char M[1000];
int A[10][10],S[45000][10],k,n;
int permutation()
{
    int p[10];
    for(int i=0; i<n; i++)p[i]=i;
    do
    {
        for(int i=0; i<n; i++)S[k][i]=p[i];
        k++;
    }
    while(next_permutation(p,p+n));
}
int main()
{
    while(cin>>M)
    {
        if(M[0]=='#')break;
        else
        {
            int vis[120];
            char C[12];
            n=0;
            memset(A,0,sizeof(A));
            memset(vis,0,sizeof(vis));
            int len=strlen(M);
            for(int i=0;i<len; i++)
                if(M[i]>='A'&&M[i]<='Z'&&!vis[M[i]])
                {
                    C[n++]=M[i];
                    vis[M[i]]=1;
                }
            sort(C,C+n);
            for(int i=0;i<len; i++)
                for(int kk=0; kk<n; kk++)
                    if(M[i]==C[kk])M[i]='A'+kk;
            for(int i=0;i<len; i++)
            {
                int a=M[i]-'A';
                i+=2;
                while(M[i]&&M[i]!=';')
                {
                    A[a][M[i]-'A']=1;
                    A[M[i]-'A'][a]=1;
                    i++;
                }
            }
            k=0;
            permutation();
            int min=10000,d;
            for(int i=0; i<k; i++)
            {
                int mm=0;
                for(int j=0; j<n-1; j++)
                {
                    int ma=0;
                    for(int c=j+1; c<n; c++)
                        if(A[S[i][j]][S[i][c]])ma=ma>c-j?ma:c-j;
                    mm=mm>ma?mm:ma;
                }
                if(mm<min)
                {
                    d=i;
                    min=mm;
                }
            }
            for(int i=0; i<n; i++)
                cout<<C[S[d][i]]<<' ';
            cout<<"-> "<<min<<endl;
        }
    }
    return 0;
}
