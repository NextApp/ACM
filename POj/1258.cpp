#include<iostream>
#include<cstdio>
#include<cstdio>
#define INF 100000000
using namespace std;
int M[120][120],V[120];
int Mintree(int n)
{
    for(int i=1;i<n;i++)
    V[i]=INF;
    V[0]=0;
    int s=n-1,f=0,sum=0;
    while(s--)
    {
        for(int i=0;i<n;i++)
        if(M[i][f]&&V[i])
            V[i]=min(M[i][f],V[i]);
        int minedge=INF;
        for(int i=0;i<n;i++)
        if(V[i]&&V[i]<minedge)
        {
            minedge=V[i];
            f=i;
        }
        V[f]=0;
        sum+=minedge;
    }
    return sum;
}
int main()
{
    int n;
   // freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>M[i][j];
            cout<<Mintree(n)<<endl;
    }
    return 0;
}
