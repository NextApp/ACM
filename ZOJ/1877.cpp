#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,a[1200];
struct T
{
    long long num,a,b;
}A[20000];
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        long long m=n,sum=0,t=0;
        while(m>=4)
        {
            if(a[0]+a[m-2]<2*a[1])
            {
                sum+=2*a[0]+a[m-1]+a[m-2];
                A[t].num=2,A[t].a=a[0],A[t++].b=a[m-2];
                A[t].num=1,A[t++].a=a[0];
                A[t].num=2,A[t].a=a[0],A[t++].b=a[m-1];
                A[t].num=1,A[t++].a=a[0];
            }
            else
            {
            sum+=a[1];A[t].num=2,A[t].a=a[0],A[t++].b=a[1];
            sum+=a[0];A[t].num=1,A[t++].a=a[0];
            sum+=a[m-1];A[t].num=2,A[t].a=a[m-2],A[t++].b=a[m-1];
            sum+=a[1];A[t].num=1,A[t++].a=a[1];
            }
            m-=2;
        }
        if(m==2)
        {
            sum+=a[1];
            A[t].num=2,A[t].a=a[0],A[t++].b=a[1];
        }
        else if(m==1)
        {
            sum+=a[0];
            A[t].num=1,A[t++].a=a[0];
        }
        else if(m==3)
        {
            sum+=a[2];
            A[t].num=2,A[t].a=a[0],A[t++].b=a[2];
            sum+=a[0];
            A[t].num=1,A[t++].a=a[0];
            sum+=a[1];
            A[t].num=2,A[t].a=a[0],A[t++].b=a[1];
        }
        cout<<sum<<endl;
        for(int i=0;i<t;i++)
        if(A[i].num==2)
        cout<<A[i].a<<' '<<A[i].b<<endl;
        else cout<<A[i].a<<endl;
    }
    return 0;
}
