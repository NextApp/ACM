#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10000
using namespace std;
long long d[N],v[6],p[6];
int main()
{
   // freopen("1.txt","r",stdin);
    int T,id=1;
    cin>>T;
    while(T--)
    {
        double m=0;
        int t;
        for(int i=0; i<3; i++)
        {
            cin>>v[i]>>p[i];
            double s=(1.0*p[i])/v[i];
            if(s>m)
            {
                m=s;
                t=i;
            }
        }
        memset(d,-1,sizeof(d));
        d[0]=0;
        long long S=6000,V;
        for(long long j=1;j<=S;j++)
        for(int i=0;i<3;i++)
        if(j>=v[i])if(d[j]<d[j-v[i]]+p[i])d[j]=d[j-v[i]]+p[i];
                cin>>V;
        long long sum=(V/v[t])*p[t];
        for(long long j=1; j<=S&&V-j>=0; j++)
        {
            long long s=((V-j)/v[t])*p[t]+d[j];
            sum=max(s,sum);
        }
        cout<<"Case "<<id++<<": "<<sum<<endl;
    }
    return 0;
}
