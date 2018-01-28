#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int M[220][220],N,R,c[220],D[220];
int find(int u)
{
    D[u]=1;
    for(int i=0; i<N; i++)
        if(M[u][i])
        {
            M[u][i]=0;
            find(i);
        }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>N>>R)
    {
        memset(M,0,sizeof(M));
        memset(c,0,sizeof(c));
        memset(D,0,sizeof(D));
        int a,b;
        for(int i=0; i<R; i++)
        {
            cin>>a>>b;
            M[a][b]=1;
            M[b][a]=1;
            c[a]++;
            c[b]++;
        }
        int OK=1;
        for(int i=0; i<N; i++)
            if(c[i]%2)
            {
                OK=0;
                break;
            }
        if(OK)
        {
            int sum=0;
            find(a);
            for(int i=0; i<N; i++)
            {
                if(c[i])sum++;
                if(D[i])sum--;
            }
            if(sum)OK=0;
        }
        if(OK)cout<<"Possible"<<endl;
        else cout<<"Not Possible"<<endl;
    }
    return 0;
}
