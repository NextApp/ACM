#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107
,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223
,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337
,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457
,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593
,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719
,727,733,739,743,751,757,761};
int pow_mod(long long m,long long  n,long long k)
{
    long long b = 1;
    while (n > 0)
    {
          if (n & 1)b = (b*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return b;
}
int feima(int p)
{
    for(int i=10;i<13;i++)
    if(p!=prime[i]&&pow_mod(prime[i],p-1,p)!=1)return 0;
    return 1;
}
int main()
{
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
            if(feima(s))
            {
                printf(" %d %d\n",prime[i],s);
                break;
            }
        }
    }
    return 0;
}
