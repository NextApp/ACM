#include<stdio.h>
#include<string.h>
int k,m,n;
char S[10][10];
int main()
{
    strcpy(S[0],"fill A");
    strcpy(S[1],"empty A");
    strcpy(S[2],"fill B");
    strcpy(S[3],"empty B");
    strcpy(S[4],"pour A B");
    strcpy(S[5],"pour B A");
    while(scanf("%d%d%d",&m,&n,&k)==3)
    {
        int a=0,b=0,o=0;
        while(1)
        {
            if(!a)
            {
                printf("%s\n",S[0]);
                a=m;
            }
            else
            {
                printf("%s\n",S[4]);
                b+=a;
                a=0;
            }
            if(b==k)
            {
                printf("success\n");
                break;
            }
            if(b>=n)
            {
                a=b-n;
                printf("%s\n",S[3]);
                b=0;
            }
        }
    }
    return 0;
}
