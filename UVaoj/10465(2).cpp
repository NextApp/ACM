#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,t,a[5],d[11000],k=0;
int dp(int S)
{
    if(!S)return 0;
    if(d[S]!=-1)return d[S];
    int t=-3;
    for(int i=0; i<2; i++)
        if(S-a[i]>=0)
        {
            int s=dp(S-a[i]);
            if(s!=-3)t=max(t,s+1);
        }
    return d[S]=t;
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>m>>n>>t)
    {
        memset(d,-1,sizeof(d));
        a[0]=m,a[1]=n;
        int s=t;
        if(t<m&&t<n)
        {
            cout<<0<<' '<<t<<endl;
            continue;
        }
        while(s>0)
        {
            int count=dp(s);
            if(count>=0)
            {
                if(s==t)cout<<count<<endl;
                else cout<<count<<' '<<t-s<<endl;
                break;
            }
            s--;
        }
    }
    return 0;
}
