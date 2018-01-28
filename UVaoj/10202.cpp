#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100
using namespace std;
int a[N],s,e,sum,sn,an,A[30],OK,S,n;
int b[N];
int judge(int cur)
{
    int aa[12];
    if((sum-S)%(n-2)!=0)return 0;
    aa[0]=(sum-S)/(n-2);
    aa[1]=a[0]-aa[0];
    aa[2]=a[1]-aa[0];
    for(int i=0; i<cur; i++)
        aa[i+3]=a[A[i]+s]-aa[0];
    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            b[cnt++]=aa[i]+aa[j];
    sort(b,b+cnt);
    for(int i=s; i<=e; i++)
        if(a[i]!=b[i])return 0;
    sort(aa,aa+n);
    for(int i=0; i<n-1; i++)
        printf("%d ",aa[i]);
    printf("%d\n",aa[n-1]);
    return 1;
}
void print_subset(int cur,int L)
{
    if(OK)return;
    if(cur==an)
    {
        sum=L;
        for(int i=0; i<cur; i++)
                sum+=a[A[i]+s];
        if(judge(cur))OK=1;
        return;
    }
    int s =cur?A[cur-1]+1:0;
    for(int i=s; i<sn; i++)
    {
        A[cur]=i;
        print_subset(cur+1,L);
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        OK=0;
        int cnt=0;
        S=0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                scanf("%d",&a[cnt++]);
                S+=a[cnt-1];
            }
        if(S%(n-1)==0)
        {
            S=S/(n-1);
            sort(a,a+cnt);
            sum=a[0]+a[1];
            s=2,e=(n-1)*n/2-n+1;
            sn=e-s+1;
            an=n-3;
            print_subset(0,sum);
        }
        if(!OK)printf("Impossible\n");
    }
    return 0;
}
