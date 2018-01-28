#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500
#define LL long long
using namespace std;
LL a,b;
bool judge(LL x,LL y)
{
    if(b*x>a*y)return 0;
    return 1;
}
void build(LL w[10])
{
    if(w[2]==a&&w[3]==b)
    {
        printf("\n");
        return ;
    }
    if(judge(w[2],w[3]))
    {
        printf("R");
         w[0]=w[2];
         w[1]=w[3];
         w[2]+=w[4];
         w[3]+=w[5];
         build(w);
    }
    else
    {
        printf("L");
        w[4]=w[2];
        w[5]=w[3];
        w[2]+=w[0];
        w[3]+=w[1];
        build(w);
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>a>>b)
    {
        if(a==1&&b==1)return 0;
        long long w[10];
        w[0]=0,w[1]=1,w[2]=1,w[3]=1,w[4]=1,w[5]=0;
        build(w);
    }
    return 0;
}
