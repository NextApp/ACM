#include<iostream>
#include<cmath>
using namespace std;
int NNS(int s)
{
    int i;
    int a=(int)sqrt(2*s);
    for(i=a;i*(i+1)<=2*s;i++);
    return i-1;
}
int main()
{
    int s;
    while(cin>>s)
    {
        int m=NNS(s);
        cout<<m<<endl;
    }
}
