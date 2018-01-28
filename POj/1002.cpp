#include<cstdio>
#include<cstdlib>
int cmp_int(const void *_a,const void *_b)
{
    int *a=(int *)_a;
    int *b=(int *)_b;
    return *a-*b;
}
const char ab[]="2223334445556667077888999";
char a[103000],b[1020];
unsigned int MM[10000000],s[101000];
int main()
{
    int num,n=0;
    scanf("%d",&num);
    for(int i=0; i<num; i++)
    {
        scanf("%s",b);
        int sum=0;
        for(int j=0; b[j]; j++)
        {
            if(b[j]<='Y'&&b[j]>='A')
                sum=10*sum+ab[b[j]-'A']-'0';
            else if(b[j]>='0'&&b[j]<='9')
                sum=10*sum+b[j]-'0';
        }
        MM[sum]++;
        s[n++]=sum;
    }
    int flag=0;
    qsort(s,n,sizeof(int),cmp_int);
    for(int i=0; i<n; i++)
    {
        if(MM[s[i]]>=2)
        {
            flag=1;
            printf("%03d-%04d %d\n",s[i]/10000,s[i]%10000,MM[s[i]]);
            MM[s[i]]=0;
        }
    }
    if(!flag)
        printf("No duplicates.\n");
    return 0;
}
