#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 100000000
#define M(_a,_b) _a>_b?_a:_b;
using namespace std;
long double a,b,m,n;
int main()
{
    while(cin>>m>>n>>a>>b)
    {
        long double s=1,t1=1,t2=1,t3=1,t4=1,t5=1,t6=1;
        while(1)
        {
            int ok=1;
            while(s*t1<=INF&&t1<=m)
                s*=t1++,ok=0;
            while(s*t2<=INF&&t2<=b)
                s*=t2++,ok=0;
            while(s*t3<=INF&&t3<=a-b)
                s*=t3++,ok=0;
            if(t4<=n)
                s/=t4++,ok=0;
            if(t5<=a)
                s/=t5++,ok=0;
            if(t6<=m-n)
                s/=t6++,ok=0;
            if(ok)break;
        }
        printf("%.5llf\n",s);
    }
    return 0;
}
