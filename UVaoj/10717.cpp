#include<iostream>
#include<cstring>
#include<cstdio>
#define INF (1<<31)-1
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    freopen("1.txt","r",stdin);
    int n,t,a[60];
    while(cin>>n>>t)
    {
        if(!n&&!t)return 0;
        else
        {
            for(int i=0; i<n; i++)
                cin>>a[i];
            int s;
            for(int x=0;x<t;x++)
            {
                int o,r1=0,r2=INF;
                cin>>o;
                for(int i=0; i<n-3; i++)
                for(int j=i+1; j<n-2; j++)
                {
                    int m=a[i]*a[j]/gcd(a[i],a[j]);
                    for(int k=j+1; k<n-1; k++)
                    {
                        int nn=m*a[k]/gcd(m,a[k]);
                        for(int d=k+1; d<n; d++)
                                {
                                    s=nn*a[d]/gcd(nn,a[d]);
                                    int x1,x2;
                                    if(!(o%s))x1=x2=o;
                                    else x1=(o/s)*s,x2=(o/s+1)*s;
                                    r1=max(x1,r1);
                                    r2=min(x2,r2);
                                }
                    }
                }
                cout<<r1<<' '<<r2<<endl;
            }
        }
    }
    return 0;
}
