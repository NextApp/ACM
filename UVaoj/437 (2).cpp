#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct T
{
    int a,b,c;
} A[100];
int G[100][100],d[100],n;
int main()
{
    freopen("1.txt","r",stdin);
    int id=1;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            for(int i=0; i<n; i++)
            {
                cin>>A[i].a>>A[i].b>>A[i].c;
                A[i+n].a=A[i].b,A[i+n].b=A[i].c,A[i+n].c=A[i].a;
                A[i+n+n].a=A[i].c,A[i+n+n].b=A[i].a,A[i+n+n].c=A[i].b;
            }
            memset(G,0,sizeof(G));
            memset(d,0,sizeof(d));
            n*=3;
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if((A[i].a<A[j].a&&A[i].b<A[j].b)||(A[i].a<A[j].b&&A[i].b<A[j].a)) G[i][j]=1;
            int m=0;
            for(int k=0;k<n/3;k++)  //n/3´ÎËÉ³Ú
            for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                    if(G[i][j])d[i]=max(d[i],d[j]+A[j].c);
            for(int i=0; i<n; i++)
                m=max(d[i]+A[i].c,m);
            cout<<"Case "<<id++<<": maximum height = "<<m<<endl;
        }
    }
    return 0;
}
