#include<iostream>
#include<cstring>
using namespace std;
int a[110][110];
int M[110][110],mx;
int R,C;
int RC(int m,int n,int id)
{
    if(m>=0&&n>=0)
    {
        if(m<R-1&&a[m+1][n]<a[m][n])
        {
            if(M[m+1][n]>1)RC(-1,-1,id+M[m+1][n]);
            else M[m+1][n]=0,RC(m+1,n,id+1);
        }
        if(m>0&&a[m-1][n]<a[m][n])
        {
            if(M[m-1][n]>1)RC(-1,-1,id+M[m-1][n]);
            else M[m-1][n]=0,RC(m-1,n,id+1);
        }
        if(n>0&&a[m][n-1]<a[m][n])
        {
            if(M[m][n-1]>1)RC(-1,-1,id+M[m][n-1]);
            else M[m][n-1]=0,RC(m,n-1,id+1);
        }
        if(n<C-1&&a[m][n+1]<a[m][n])
        {
            if(M[m][n+1]>1)RC(-1,-1,id+M[m][n+1]);
            else M[m][n+1]=0,RC(m,n+1,id+1);
        }
    }
    if(id>mx)mx=id;
}
int main()
{
    cin>>R>>C;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin>>a[i][j];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            M[i][j]=1;
    int max=0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            if(M[i][j])
            {
                mx=0;
                RC(i,j,1);
                M[i][j]=mx;
                if(max<mx)max=mx;
            }
        }
    cout<<max<<endl;
    return 0;
}
