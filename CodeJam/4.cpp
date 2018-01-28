#include<iostream>
#include<cstdio>
using namespace std;
int solve(int A, int B)
{
    int power = 1, temp = A;
    while (temp >= 10)
    {
        power *= 10;
        temp /= 10;
    }
    int ret = 0;
    for (int n = A; n <= B; ++n)
    {
        temp = n;
        while (true)
        {
            temp = (temp / 10) + ((temp % 10) * power);
            if (temp == n)
                break;
            if (temp > n && temp >= A && temp <= B)
                ret++;
        }
    }
    return ret;
}

int main()
{
    int n;
    freopen("C-large-practice.in","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int A,B,sum;
        scanf("%d%d",&A,&B);
        sum=solve(A,B);
        printf("Case #%d: %d\n",i+1,sum);
    }
    return 0;
}
