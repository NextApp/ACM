#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,num,d[1000100],a[12];
int main()
{
    while(scanf("%d%d",&n,&num)==2)
    {
        for(int i=0; i<num; i++)
            scanf("%d",&a[i]);
        sort(a,a+num);
        d[0]=d[1]=1;
        for(int j=2; j<=n; j++)
        {
            d[j]=0;
            for(int i=0; i<num; i++)
                if((j==a[i])||(j>a[i]&&!d[j-a[i]]))
                {
                    d[j]=1;
                    break;
                }
                else if(j<a[i])break;
        }
        if(d[n])printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}
