#include<cstdio>
#define eps 1e-6
#define pi 3.14159265
int main()
{
    double x,y;
    int n,id=1;
    while(~scanf("%d",&n))
    {
        int i=0;
        for(i=0; i<n; i++)
        {
            scanf("%lf%lf",&x,&y);
            printf("Property %d: This property will begin eroding in year %d.\n",id++,int(((x*x+y*y)*pi/2.0/50)+eps)+1);
        }
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
