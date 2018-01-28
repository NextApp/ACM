#include<cstdio>
int main()
{
    double x,y,z;
    while(~scanf("%lf%lf%lf",&x,&y,&z))
    {
        x+=y;
        printf("%.5lf\n",(x-1)*y/(x*(x-z-1)));
    }
}
