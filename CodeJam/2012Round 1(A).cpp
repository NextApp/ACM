#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double a[250];
int cmp(const int i,const int j)
{
    return a[i]<a[j];
}
int n;
int main()
{
    freopen("A-large-practice.in.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int T,id=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        double m=100000,sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            m=min(a[i],m);
        }
        int p[300],d;
        double s,M[250];
        for(int i=0; i<n; i++)
            p[i]=i;
        sort(p,p+n,cmp);
        int ok=1;
        for(d=n; d>=1; d--)
        {
            s=0;
            for(int i=0; i<d; i++)
                s+=-m/sum+a[p[i]]/sum;
            s+=1;
            s/=d;
            ok=1;
            for(int i=0; i<d; i++)
                if(s+m/sum-a[p[i]]/sum<0)
                {
                    ok=0;
                    break;
                }
            if(ok)break;
        }
        memset(M,0,sizeof(M));
        for(int i=0; i<d; i++)
            M[p[i]]=(s+m/sum-a[p[i]]/sum)*100;
        cout<<"Case #"<<id++<<": ";
        for(int i=0; i<n-1; i++)
            printf("%.6lf ",M[i]);
        printf("%.6lf\n",M[n-1]);
    }
    return 0;
}
