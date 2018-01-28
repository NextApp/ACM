#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    int n;
    double a[40],t;
    while(cin>>n>>t)
    {
        if(!n&&!t)return 0;
        else
        {
            a[0]=pow(2,n);
            for(int i=1; i<=n; i++)
            {
                double ep=pow(2,n-i)/a[i-1];
                if(ep<=t)a[i]=(1+t)/2*a[i-1];
                else
                    a[i]=(ep-t)/(1-t)*pow(2,n-i)+((1-ep)/(1-t))*(1+ep)/2*a[i-1];
            }
            printf("%.3lf\n",a[n]);
        }
    }
    return 0;
}
