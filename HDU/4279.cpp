#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL unsigned long long
using namespace std;
LL b_search(LL a)
{
    LL s=1,E=(LL)1<<32;
    while(s<=E)
    {
        LL k= (s+E)/2;
        if(k*k>a&&(k-1)*(k-1)<=a)return k-1;
        else if((k-1)*(k-1)>a)
        {
            E=k-1;
        }
        else s=k+1;
    }
    return ((LL)1<<32)-1;
}
LL count(LL a)
{
    if(!a)return 0;
    LL sum=0;
    LL s=b_search(a);
    sum=a/2-s/2+(s-1)/2;
    if(a>=2)sum--;
    return sum;
}
LL a,b;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>a>>b;
        cout<<count(b)-count(a-1)<<endl;
    }
    return 0;
}
