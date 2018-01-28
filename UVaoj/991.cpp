#include<cstdio>
using namespace std;
int main()
{
    int n,id=0;
    int a[15]={0,1,2,5,14,42,132,429,1430,4862,16796};
    while(~scanf("%d",&n))
    {
        if(id)printf("\n");
        id=1;
        printf("%d\n",a[n]);
    }
    return 0;
}
