#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[530][8],d[530][8];
int dx[]= {1,0,3,2,5,4},k;
char S[10][10];
struct T
{
    int a,b;
} M[530];
void print(int x,int y)
{
    M[k].a=x+1,M[k++].b=dx[y];
    for(int i=0; i<x; i++)
        for(int j=0; j<6; j++)
        {
            if(d[x][y]==d[i][j]+1&&a[x][dx[y]]==a[i][j])
            {
                print(i,j);
                return ;
            }
        }
}
int main()
{
    strcpy(S[0],"front");
    strcpy(S[1],"back");
    strcpy(S[2],"left");
    strcpy(S[3],"right");
    strcpy(S[4],"top");
    strcpy(S[5],"bottom");
  //  freopen("1.txt","r",stdin);
    int id=0;
    while(cin>>n&&n)
    {
        if(id)cout<<endl;
        for(int i=0; i<n; i++)
            for(int j=0; j<6; j++)
            {
                cin>>a[i][j];
                d[i][j]=1;
            }
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                for(int k=0; k<6; k++)
                    for(int t=0; t<6; t++)
                        if(a[j][k]==a[i][t])
                            d[i][dx[t]]=max(d[i][dx[t]],d[j][k]+1);
        int t=0,x,y;
        for(int i=0; i<n; i++)
            for(int j=0; j<6; j++)
                if(t<d[i][j])
                {
                    x=i,y=j;
                    t=d[i][j];
                }
        k=0;
        print(x,y);
        cout<<"Case #"<<++id<<endl<<t<<endl;
        for(int i=k-1; i>=0; i--)
            cout<<M[i].a<<' '<<S[M[i].b]<<endl;
    }
    return 0;
}
