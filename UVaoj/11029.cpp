#include<cmath>
#include<cstdio>
#define N 1000
int mmm(int m,int n)
{
    if(n==1)return m%N;
    int s=mmm(m,n/2);
    if(!(n%2))return (s*s)%N;
    else return ((s*s)%N*(m%N))%N;
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        int l=mmm(a,b);
        int o=(int)pow(10,2+fmod(b*log10(a),1));
        printf("%d...%03d\n",o,l);
    }
    return 0;
}
