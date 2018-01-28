#include<stdio.h>
#include<string.h>
int A[1020000];
int main()
{
    int a,b,m,count,max,i,temp;
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%d %d ",a,b);
        if(a>b)
        {
            temp=a,a=b,b=temp;
        }
        memset(A,1,sizeof(A));
        max=0;
        for(i=b; i>=a; i--)
            if(A[i])
            {
                count=0;
                m=i;
                while(m!=1)
                {
                    if(!(m%2))m/=2;
                    else if(m%2)m=3*m+1;
                    count++;
                    if(m<b&&m>=a)A[m]=0;
                }
                if(count>max)max=count;
            }
        printf("%d\n",max+1);
    }
    return 0;
}
