#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c,d;
int A,B;
int P(int a,int b)
{
    if(a==12)return b*60;
    else return (60*a+b)*60;
}
double Shidu(int a)
{
    return fmod(a*0.5*(1.0/60),360);
}
double fendu(int a)
{
    return fmod(a*0.1,360);
}
int main()
{
   // freopen("1.txt","r",stdin);
    cout<<"Program 3 by team X"<<endl;
    cout<<"Initial time  Final time  Passes"<<endl;
    while(cin>>a>>b>>c>>d)
    {
        A=P(a,b),B=P(c,d);
        if(B<A)B+=12*60*60;
        int count=0;
        for(int i=A;i<B;i++)
        {
            int aa=Shidu(i),bb=fendu(i);
            if(fabs(aa-bb)<0.1)
            {
                i+=60;
                count++;
            }
        }
        printf("       %02d:%02d       %02d:%02d%8d\n",a,b,c,d,count);
    }
    cout<<"End of program 3 by team X"<<endl;
    return 0;
}
