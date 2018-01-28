#include<stdio.h>
int main()
{
    int i,j,num,n,mm,a,v,s,k,e;
    scanf("%d",&num);
    for(i=0; i<num;)
    {
        mm=-1001,v=0,s=0,k=0,e=0;
        scanf("%d",&n);
        if(i)printf("\n");
        for(j=0; j<n; j++)
            {
                scanf("%d",&a);
                v+=a;
                if(v>mm)mm=v,s=k,e=j;
                if(v<0)v=0,k=j+1;
            }
        printf("Case %d:\n%d %d %d\n",++i,mm,s+1,e+1);
    }
    return 0;
}
