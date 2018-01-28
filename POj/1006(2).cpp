#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int p,e,i,d,ans,id=1;
    while(~scanf("%d%d%d%d",&p,&e,&i,&d)&&p!=-1)
    {
        ans = (p*5544+14421*e+1288*i)%21252-d;
        while(ans<=0)ans+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",id++,ans);
    }
    return 0;
}
