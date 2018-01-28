#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct D
{
    int a,b;
}A1[30],A2[30];
int S;
int cmp1(const void *_a,const void *_b)
{
    D*a=(D*)_a;
    D*b=(D*)_b;
    if(a->a-b->a)return a->a-b->a;
}
int cmp2(const void*_a,const void*_b)
{
    D*a=(D*)_a;
    D*b=(D*)_b;
    if(b->b-a->b)return b->b-a->b;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,s=0,a1=0,a2=0,p1,p2,p3,P;
        cin>>n>>S;
        for(int i=0; i<n; i++)
        {
            cin>>p1>>p2>>p3>>P;
            int l=p1+p1+p1;
            int sum=l;
            l=2*p1+p3;
            sum=min(sum,l);
            l=2*p1+p2;
            sum=min(sum,l);
            l=p1+2*p2;
            sum=min(sum,l);
            l=p1+p2+2*p3;
            sum=min(sum,l);
            l=p1+4*p3;
            sum=min(sum,l);
            l=p2+5*p3;
            sum=min(sum,l);
            l=2*p2+3*p3;
            sum=min(sum,l);
            l=3*p2+p3;
            sum=min(sum,l);
            l=4*p2;
            sum=min(sum,l);
            l=7*p3;
            sum=min(sum,l);
            if(P-sum>=0)
            {
                A1[a1].a=sum;
                A1[a1++].b=P;
            }
            else
            {
                A2[a2].a=sum;
                A2[a2++].b=P;
            }
        }
        qsort(A1,a1,sizeof(A1[0]),cmp1);
        qsort(A2,a2,sizeof(A2[0]),cmp2);
        int ok=1;
        for(int i=0;i<a1&&ok;i++)
        {
            if(S>A1[i].a)S+=-A1[i].a+A1[i].b;
            else ok=0;
        }
        for(int i=0;i<a2&&ok;i++)
        {
            if(S>A2[i].a)S+=-A2[i].a+A2[i].b;
            else ok=0;
        }
        if(!ok)cout<<"no"<<endl;
        else cout<<S<<endl;
    }
    return 0;
}
