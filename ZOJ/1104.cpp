#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
double h,g=9.8;
int main()
{
    while(cin>>n)
    {
        double x[120],y[120],a=0,sum=0,v,c=0,b=0;
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
            c+=y[i];
        }
        sum=y[0];
        double l=0;
        for(int i=1;i<n;i++)
            {
                l=max(x[i],x[i-1]);
                a=min(l/(sum*(sum-c)),a);
                sum+=y[i];
            }
        h=-a*c*c/4;
        v=sqrt(2*g*h);
        double k=-a*c;
        printf("%.2lf %.2lf\n",atan(-a*c)*180/3.14159265358,sqrt(1+1/(k*k))*v);
    }
    return 0;
}
