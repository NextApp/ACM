#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct T
{
    double a,b,c,d;
} q[10330];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->c!=b->c)return a->c>b->c;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int num,l,m;
    while(cin>>num>>l>>m)
    {
        for(int i=0; i<num; i++)
        {
            cin>>q[i].a>>q[i].b;
            double a,b;
            a=q[i].a-sqrt(q[i].b*q[i].b-m*m/4.);
            b=q[i].a+sqrt(q[i].b*q[i].b-m*m/4.);
            if(a<0)a=0;
            if(b>l)b=l;
            q[i].c=a,q[i].d=b;
        }
        qsort(q,num,sizeof(T),cmp);
        double s=0;
        int i=0,sum=0,ok=0;
        while(s<l&&i<num)
        {
            double max=0;
            int ss=0;
            while(q[i].c<=s&&i<num)
            {
                if(max<q[i].d)max=q[i].d;
                ss=1;
                i++;
            }
            if(ss)
            {
                s=max;
                sum++;
                i--;
            }
            i++;
        }
        if(s==l)cout<<sum<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
