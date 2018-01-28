#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int x,int y)
{
    if(!x||!y)return x+y;
    for(int t; t=x%y; x=y,y=t);
    return y;
}
int main()
{
    int T,a,b,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        if(b%a==0)
        {
            t=b/a;
            int s=gcd(a,t);
            while(s!=1)
            {
                t*=s;
                a=a/s;
                s=gcd(a,t);
            }
            printf("%d\n",t);
        }
        else printf("NO SOLUTION\n");
    }
    return 0;
}
