#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char name[20][30];
int d[20][20];
double p[20][10];
int cal(int k,int i)
{
    if(!i)
    {
        if(k%2)return k-1;
        else   return k+1;
    }
    else if(i==1)
    {
        if(k%4<2)return (k/2+1)*2;
        else return (k/2-1)*2;
    }
    else if(i==2)
    {
        if(k%8<4)return (k/4+1)*4;
        else return (k/4-1)*4;
    }
    else
    {
        if(k%16<8)return (k/8+1)*8;
        else return (k/8-1)*8;
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    for(int i=0; i<16; i++)
        scanf("%s",name[i]);
    for(int i=0; i<16; i++)
        for(int j=0; j<16; j++)
            scanf("%d",&d[i][j]);
    for(int i=0; i<=3; i++)
        for(int k=0; k<16; k++)
        {
            double s=0;
            int l=pow(2,i),o=cal(k,i);
            for(int j=o; j<l+o; j++)
                s+=(i>0?p[j][i-1]:1)*d[k][j]/100.0;
            if(i>0)p[k][i]=p[k][i-1]*s;
            else p[k][i]=s;
        }
    int l=0;
    for(int i=0; i<16; i++)
    {
        printf("%s",name[i]);
        int len=strlen(name[i]);
        for(; len<11; len++)printf(" ");
        printf("p=%.2lf",p[i][3]*100);
        puts("%");
    }
    return 0;
}
