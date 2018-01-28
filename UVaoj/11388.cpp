#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a,b,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(b%a==0)printf("%d %d\n",a,b);
        else printf("-1\n");
    }
    return 0;
}
