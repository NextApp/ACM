#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,P[1200],W[1200],G[120],f[35];
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>m;
        for(int i=1; i<=m; i++)
            cin>>P[i]>>W[i];
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>G[i];
        int sum=0;
        for(int k=0; k<n; k++)
        {
            memset(f,0,sizeof(f));
            for(int i=1; i<=m; i++)
                for(int j=G[k]; j>=0; j--)
                    if(j>=W[i])f[j]=max(f[j-W[i]]+P[i],f[j]);
            sum+=f[G[k]];
        }
        cout<<sum<<endl;
    }
    return 0;
}
