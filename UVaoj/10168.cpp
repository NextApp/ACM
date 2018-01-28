#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 10000000
bool p[5001000]= {false};
int prime[1000],num;
int creatprime2(int lim)
{
    int sievelimit = 1580,maxindex = lim/2;
    int n,t,k;
    for(n = 1; n <= sievelimit; n++)
        if(!p[n])
        {
            t = 2*n + 1;
            for(k = 2*n*(n+1); k <= maxindex; k += t)
                p[k] = true;
        }
    prime[0] = 2;
    num = 1;
    for(n = 1; n <= 400; n++)
        if(!p[n])prime[num++] = 2*n+1;
}
int main()
{
    creatprime2(MAX);
    int m;
    while(~scanf("%d",&m))
    {
        if(m<8)
        {
            puts("Impossible.");
            continue;
        }
        if(m&1)
        {
            printf("2 3");
            m-=5;
        }
        else
        {
            printf("2 2");
            m-=4;
        }
        for(int i=0;;i++)
        {
            int s=m-prime[i];
            if((s%2||s==2)&&!p[s/2])
            {
                printf(" %d %d\n",prime[i],m-prime[i]);
                break;
            }
        }
    }
    return 0;
}
