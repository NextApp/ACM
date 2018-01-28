#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int S,n,I;
    cin>>S;
    while(S--)
    {
        double p;
        cin>>n>>p>>I;
        if(p==0)printf("0.0000\n");
        else
        {
            double s=(p*pow(1-p,I-1))/(1-pow(1-p,n));
            printf("%.4lf\n",s);
        }
    }
    return 0;
}
