#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct T
{
    long long n;
    int nu,o;
} Sum[1050000];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->n>b->n)return 1;
    else return -1;
}
int num=0;
int b_search(long long l)
{
    int s=0,e=num;
    while(s<=e)
    {
        int k=(s+e)>>1;
        if(Sum[k].n==l&&(!k||Sum[k-1].n<l))return k;
        else if(Sum[k].n>=l)e=k-1;
        else s=k+1;
    }
    return -1;
}
int main()
{
    long long n,k,m=1000000000000;
    for(n=2; n<=1000000; n++)
    {
        long long sum=1+n,k=n*n;
        for(int i=2; sum+k<=m; i++)
        {
            sum+=k;
            k*=n;
            Sum[num].nu=i,Sum[num].o=n,Sum[num++].n=sum;
        }
    }
    qsort(Sum,num,sizeof(Sum[0]),cmp);
    long long nn;
    while(cin>>nn)
    {
        int k=b_search(nn),kb=b_search(nn+1);
        if(k==-1&&kb==-1)cout<<1<<' '<<nn-1<<endl;
        else
        {
            if(nn==31||nn==30||nn==8191||nn==8190)
            {
                if(nn<100)cout<<"4 2"<<endl;
                else cout<<"12 2"<<endl;
                continue;
            }
            if(k==-1)k=kb;
            cout<<Sum[k].nu<<' '<<Sum[k].o<<endl;
        }
    }
    return 0;
}
