#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int O[60],V[60];
int M[60][60],Vis[60][60],m;
int euler(int u)
{
    for(int i=0; i<50; i++)
        if(M[u][i])
        {
            M[u][i]--,M[i][u]--;
            euler(i);
            cout<<i+1<<' '<<u+1<<endl;
        }
}
int find(int u)
{
    for(int i=0; i<50; i++)
        if(!Vis[u][i]&&M[u][i])
        {
            V[i]=1;
            Vis[u][i]=1;
            find(i);
        }
}
int main()
{
   //  freopen("1.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int N,a,b;
        cin>>N;
        memset(O,0,sizeof(O));
        memset(M,0,sizeof(M));
        memset(V,0,sizeof(V));
        memset(Vis,0,sizeof(Vis));
        for(int j=0; j<N; j++)
        {
            cin>>a>>b;
            M[a-1][b-1]++;
            M[b-1][a-1]++;
            O[a-1]++;
            O[b-1]++;
        }
        int OK=1,s=0,ok;
        V[a-1]=1;
        find(a-1);
        for(int j=0; j<50; j++)
        {
            if(V[j])s++;
            if(O[j])s--;
        }
        if(s)OK=0;
        for(int j=0; j<50; j++)
        {
            if(O[j]%2)
            {
                OK=0;
                break;
            }
            else if(O[j])ok=j;
        }
        m=0;
        if(i)cout<<endl;
        cout<<"Case #"<<i+1<<endl;
        if(OK)euler(ok);
        else cout<<"some beads may be lost"<<endl;
    }
    return 0;
}
