#include<iostream>
#include<cstring>
using namespace std;
int a[100200];
int prime[1020];
char M[1100];
int main()
{
    int n,m,k=0;
    memset(M,1,sizeof(M));
    for(int i=2; i<100; i++)
        for(int j=2*i; j<1000; j+=i)
            M[j]=0;
    for(int j=2; j<1000; j++)
        if(M[j])prime[k++]=j;
    while(cin>>n>>m)
    {
        for(int i=0; i<n; i++)
            cin>>a[i];
        double max=0;
        int x0=1;
        for(int i=0; i<=n-m; i++)
        {
            double sum=0;
            for(int j=i; j<i+m; j++)
                sum+=a[j];
            int t=m;
            while(sum/t<=a[i+t]&&i+t<n)
                sum+=a[i+t++];
            if(sum/t>max/x0)
            {
                max=sum;
                x0=t;
            }
        }
        int s=(int)(max+0.0001);
        if(!(s%x0))cout<<s/x0<<endl;
        else
        {
            for(int j=0; j<1000&&prime[j]<x0; j++)
            {
                while(!(s%prime[j])&&!(x0%prime[j]))
                    s/=prime[j],x0/=prime[j];
            }
            cout<<s<<'/'<<x0<<endl;
        }
    }
    return 0;
}
