#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
double H,h,D;
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>H>>h>>D;
        double mm=0,b=0;
        double a=(D*h)/H;
        double s=sqrt(D*(H-h));
        double x=D*(H-h)/H;
        if(s<=D&&x<=s)b=H+D-2*s;
        else b=h;
        mm=max(mm,a);
        mm=max(mm,b);
        printf("%.3lf\n",mm);
    }
    return 0;
}
