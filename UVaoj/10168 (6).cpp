#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000000
using namespace std;
bool M[10000020]= {false};
int prime[10000000],num;
void prime_make()
{
    num=0;
    for(int i=2; i<maxn; i++)
    {
        if(!M[i])prime[num++]=i;
        for(int j=0; j<num&&i*prime[j]<maxn; j++)
        {
            M[i*prime[j]]=true;
            if(0==i%prime[j])break;
        }
    }
}
int main()
{
    prime_make();
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
        for(int i=0;; i++)
            if(!M[m-prime[i]])
            {
                printf(" %d %d\n",prime[i],m-prime[i]);
                break;
            }
    }
    return 0;
}
