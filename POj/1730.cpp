#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long x;
    while(cin>>x)
    {
        if(!x)break;
        else
        {
            if(x>0)
            {
                int max=1;
                for(double i=2; i<=32; i++)
                {
                    long long s=(long long)(pow(x,1/i)+0.001);
                    if(x==pow(s,i))
                        max=i;
                }
                cout<<max<<endl;
            }
            else
            {
                int max=1;
                x=-x;
                for(double i=2; i<=32; i++)
                {
                    long long s=(long long)(pow(x,1/i)+0.001);
                    if(x==pow(s,i)&&(int)i%2)
                        max=i;
                }
                cout<<max<<endl;
            }
        }
    }
    return 0;
}
