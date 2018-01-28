#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MA 10000007
using namespace std;
int n,a[120],m,A[30][30],B[30][30],d;
struct T
{
    int x,y,u,t,num;
} P[120];
void Matrix_Mul(int A[][30],int B[][30],int C[][30])
{
    int D[30][30];
    memset(D,0,sizeof(D));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(A[i][j])
            {
                long long sum=0;
                for(int k=1; k<=n; k++)
                    D[i][k]=(D[i][k]+(long long)A[i][j]*B[j][k])%MA;
            }
    memcpy(C,D,sizeof(D));
}
int Pow(int A[][30],int B[][30],int m)
{
    if(m==1)return 0;
    int n=m/2;
    Pow(A,B,n);
    Matrix_Mul(B,B,B);
    if(m%2)Matrix_Mul(B,A,B);
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
            cin>>a[i];
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for(int i=1; i<=n; i++)
            A[i][i]=B[i][i]=1;
        cin>>m;
        for(int j=0; j<m; j++)
        {
            char c[120];
            cin>>c;
            int x,y,u,t;
            if(!strcmp("transform",c))
            {
                cin>>P[j].x>>P[j].y>>P[j].u>>P[j].t;
                x=P[j].x,y=P[j].y,u=P[j].u,t=P[j].t;
                P[j].num=1;
                B[y][y]=B[t][y]=0;
                B[y][y]+=x;
                B[t][y]+=u;
                B[t][t]=0;
            }
            else if(!strcmp("remove",c))
            {
                cin>>P[j].x;
                x=P[j].x;
                P[j].num=2;
                B[x][x]=0;
            }
            else if(!strcmp("double",c))
            {
                cin>>P[j].x;
                x=P[j].x;
                P[j].num=4;
                B[x][x]=2;
            }
            else
            {
                cin>>P[j].x>>P[j].y;
                x=P[j].x,y=P[j].y;
                if(!strcmp("add",c))
                {
                    B[y][x]++,P[j].num=3;
                }
                else if(!strcmp("invert",c))
                {
                    for(int i=x; i<=y; i++)
                        B[i][i]=0;
                    for(int i=x,k=y; i<=y; i++,k--)
                        B[i][k]=1;
                    P[j].num=5;
                }
                else
                {
                    P[j].num=6;
                    B[x][x]=B[y][y]=0;
                    B[x][y]=B[y][x]=1;
                }
            }
            Matrix_Mul(A,B,A);
            memset(B,0,sizeof(B));
            for(int i=1; i<=n; i++)
                B[i][i]=1;
        }
        cin>>d;
        if(d/m)
        {
            memcpy(B,A,sizeof(A));
            Pow(A,B,d/m);
        }
        for(int j=0; j<d%m; j++)
        {
            memset(A,0,sizeof(A));
            for(int i=1; i<=n; i++)
                A[i][i]=1;
            int c=P[j].num,x=P[j].x,y=P[j].y,u=P[j].u,t=P[j].t;
            if(c==1)
            {
                A[y][y]=A[t][y]=0;
                A[y][y]+=x;
                A[t][y]+=u;
                A[t][t]=0;
            }
            else if(c==2)A[x][x]=0;
            else
            {

                if(c==3)A[y][x]++;
                else if(c==4)A[x][x]=2;
                else if(c==5)
                {
                    for(int i=x; i<=y; i++)
                        A[i][i]=0;
                    for(int i=x,k=y; i<=y; i++,k--)
                        A[i][k]=1;
                }
                else
                {
                    A[x][x]=A[y][y]=0;
                    A[x][y]=A[y][x]=1;
                }
            }
            Matrix_Mul(B,A,B);
        }
        memset(A,0,sizeof(A));
        for(int i=1; i<=n; i++)A[1][i]=a[i];
        Matrix_Mul(A,B,A);
        for(int i=1; i<n; i++)
            cout<<A[1][i]<<' ';
        cout<<A[1][n]<<endl;
    }
    return 0;
}
