#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int YXO(int a)
{
    int i=(int)sqrt(2*a);
    for(;i*(i+1)<=2*a;i++)
    if(i*(i+1)==a)return i;
    return i-1;
}
int main()
{
    int a;
    while(cin>>a)
    {
        if(!a)break;
        else
        {
            cout<<a<<' ';
            int n=YXO(a);
            cout<<(n*(n+1)*(2*n+1))/6+(a-n*(n+1)/2)*(n+1)<<endl;
        }

    }
    return 0;

}
