#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,L[105],mm,M[105][105],O[108];
int dfs(int i)
{
    for (int k=1;k<=n;k++)
        if (M[i][k]&&!O[k])dfs(k);
    L[mm--]=i;
    O[i]=1;
}
int main()
{
    while (cin>>n>>m)
    {
        if (!n&&!m)return 0;
        else
        {
            int a,b;
            memset(O,0,sizeof(O));
            memset(M,0,sizeof(M));
            for (int i=0;i<m;i++)
            {
                cin>>a>>b;
                M[a][b]=1;
            }
            mm=n-1;
            for (int i=1;i<=n;i++)
                if (!O[i])dfs(i);
            for (int i=0;i<n-1;i++)cout<<L[i]<<' ';
            cout<<L[n-1]<<endl;
        }
    }
    return 0;
}
