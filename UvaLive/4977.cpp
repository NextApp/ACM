#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int M[1200000],N[1200000];
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0; i<num; i++)
    {
        int m,n,ok=1,nn=0,ss=0;
        scanf("%d%d",&m,&n);
        for(int j=0; j<n; j++)
        {
            scanf("%d",&N[j]);
            if(!N[j])M[ss++]=0;
            if(N[j]&&ok)
            {
                int okk=0,m,oo=ss-1;
                for(int k=j-1; k>=0; k--)
                {
                    if(!N[k]&&!M[oo])
                    {
                        m=oo--;
                        okk=1;
                        if(oo<0)break;
                    }
                    else if(N[k]==N[j])
                    {
                        if(!okk)ok=0;
                        break;
                    }
                }
               if(okk)M[m]=N[j];
               else ok=0;
            }
        }
        if(ok)
        {
            puts("YES");
            int kk=0;
            for(int j=0; j<ss-1; j++)
              printf("%d ",M[j]);
            printf("%d\n",M[ss-1]);
        }
        else puts("NO");
    }
    return 0;
}
