#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char a[13][3];
int A[12],M[280][6],k=0;
struct T
{
    int a;
    char b;
} S[12],O[12];
void print_subset1(int n,int s)
{
    int o=0;
    for(int i=0; i<n; i++)
        if(s&(1<<i))M[k][o++]=i;
    if(o==5)k++;
}
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->a!=b->a)return a->a-b->a;
    else return a->b-b->b;
}
int judgecolor()
{
    for(int i=0; i<4; i++)
        if(O[i].b!=O[i+1].b)return 0;
    return 1;
}
int judgeflush()
{
    for(int i=1; i<4; i++)
        if(O[i].a+1!=O[i+1].a)return 0;
    if(O[0].a==1&&O[1].a==10)return 1;
    else if(O[0].a+1==O[1].a)return 1;
    return 0;
}
int judgenum()
{
    int B[20];
    memset(B,0,sizeof(B));
    for(int i=0; i<5; i++)
        B[O[i].a]++;
    int big=0,mm=0;
    for(int i=1; i<14; i++)
        if(B[i])
        {
            big=big>B[i]?big:B[i];
            mm++;
        }
    if(big==4)return 4;
    else if(big==3&&mm==2)return -3;
    else if(big==3&&mm==3)return 3;
    else if(big==2&&mm==3)return -2;
    else if(big==2&&mm==4)return 2;
    else return 0;
}
int judge()
{
    int r;
    qsort(O,5,sizeof(O[0]),cmp);
    int num=judgenum();
    int color=judgecolor();
    int flush=judgeflush();
    if(color&&flush)r=1;
    else if(num==4)r=2;
    else if(num==-3)r=3;
    else if(color)r=4;
    else if(flush)r=5;
    else if(num==3)r=6;
    else if(num==-2)r=7;
    else if(num==2)r=8;
    else r=9;
    return r;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n=10;
    for(int i=0; i<(1<<n); i++)
        print_subset1(n,i);
    while(cin>>a[0])
    {
        cout<<"Hand: ";
        cout<<a[0]<<' ';
        for(int i=1; i<10; i++)
        {
            cin>>a[i];
            cout<<a[i]<<' ';
            if(i==4)cout<<"Deck: ";
        }
        for(int j=0; j<10; j++)
        {
            S[j].b=a[j][1];
            if(a[j][0]=='A')S[j].a=1;
            else if(a[j][0]=='T')S[j].a=10;
            else if(a[j][0]=='J')S[j].a=11;
            else if(a[j][0]=='Q')S[j].a=12;
            else if(a[j][0]=='K')S[j].a=13;
            else S[j].a=a[j][0]-'0';
        }
        int min=10;
        for(int i=0; i<k; i++)
        {
            int oo[12],max=0;
            memset(oo,0,sizeof(oo));
            for(int j=0; j<5; j++)
            {
                oo[M[i][j]]=1;
                max=M[i][j]>max?M[i][j]:max;
                O[j].a=S[M[i][j]].a;
                O[j].b=S[M[i][j]].b;
            }
            int o=judge();
            if(min>o)
            {
                int ss=0;
                for(int i=0; i<5; i++)
                    if(!oo[i])ss++;
                if(max<=4+ss)min=o;
            }
        }
        cout<<"Best hand: ";
        if(min==1)cout<<"straight-flush";
        else if(min==2)cout<<"four-of-a-kind";
        else if(min==3)cout<<"full-house";
        else if(min==4)cout<<"flush";
        else if(min==5)cout<<"straight";
        else if(min==6)cout<<"three-of-a-kind";
        else if(min==7)cout<<"two-pairs";
        else if(min==8)cout<<"one-pair";
        else cout<<"highest-card";
        cout<<endl;
    }
    return 0;
}
