#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,q[100],f[100],m;
int dfs(int h)
{
    if(h<m)
    {
        for(int i=h-1; i>=0; i--)
        {
            int c=q[i]+q[h-1];
            if(c<=n)
            {
                q[h]=c;
                if(c==n&&m>h)
                {
                    for(int j=0; j<=h; j++)
                        f[j]=q[j];
                    m=h;
                }
                else if(c*1<<(m-h-1)>=n)dfs(h+1);
            //c*1<<(m-h-1)是指在不超出的情况下c的最大增长
            }
        }
    }
}
int main()
{
    while(cin>>n&&n)
    {
        if(n==1)cout<<1<<endl;
        else
        {
            m=30;
            q[0]=1;
            dfs(1);
            for(int i=0; i<m; i++)
                cout<<f[i]<<' ';
            cout<<n<<endl;
        }
    }
    return 0;
}
