#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#define N 50
using namespace std;
int n,k,C[N],cnt,d[N][N];
void dfs(int cur,int num)
{
    if(num==k)
    {
        cnt++;
        return;
    }
    if(2*n-cur<=k-num)return;
    if(cur==2*n-1)return;
    int x,y;
    if(cur<n)x=cur,y=0;
    else x=n-1,y=cur-n+1;
    for(; x>=0&&y<n; x--,y++)
    {
        if(!C[y-x+n])
        {
            C[y-x+n]=1;
            dfs(cur+1,num+1);
            C[y-x+n]=0;
        }
    }
    dfs(cur+1,num);

}
int X[20]={1,64,1736,26192,242856,1444928,5599888,14082528,22522960,22057472,12448832,3672448
,489536,20224,256};
int D[20]={1,49,994,10894,70792,282248,692320,1022320,867328,389312,81184,5792,128};
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(!n&&!k)return 0;
        else if(n==1&&k==1)
        {
            printf("1\n");
            continue;
        }
        cnt=0;
        if(n<7)
        {
            memset(C,0,sizeof(C));
            if(k<=2*n-1)dfs(0,0);
        }
        else if(n==8&&k<15)
        {
            printf("%d\n",X[k]);
            continue;
        }
        else if(n==7&&k<13)
        {
            printf("%d\n",D[k]);
            continue;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
