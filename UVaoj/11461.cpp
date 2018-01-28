#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b)&&a+b)
    {
        int s=(int)sqrt(a);
        int num=0;
        while(s*s<=b)
        {
            if(s*s>=a)
            num++;
            s++;
        }
        printf("%d\n",num);
    }
    return 0;
}
