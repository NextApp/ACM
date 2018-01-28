#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10050
using namespace std;
int n,d[N],l[N],e[N];
struct T
{
    int a,p;
} c[N];
int binary_search(int m,int num)
{
    int a=1,b=m;
    while(a<=b)
    {
        int k=(a+b)/2,s=(k==m||c[k+1].a>num);
        if(c[k].a<num&&s)return c[k].p;
        else if(s)b=k-1;
        else a=k+1;
    }
    return -1;
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>l[i];
            d[i]=e[i]=1;
        }
        c[1].a=l[0],c[1].p=0;
        int dn=1;
        for(int i=1; i<n; i++)
        {
            int t=1;
            int k=binary_search(dn,l[i]);
            if(k>=0)t=d[i]=d[k]+1;
            if(t>dn||l[i]<c[t].a)
            {
                c[t].a=l[i];
                c[t].p=i;
                dn=max(dn,t);
            }
        }
        c[1].a=l[n-1],c[1].p=n-1;
        dn=1;
        for(int i=n-2; i>=0; i--)
        {
            int t=1;
            int k=binary_search(dn,l[i]);
            if(k>=0)t=e[i]=e[k]+1;
            if(t>dn||l[i]<c[t].a)
            {
                c[t].a=l[i];
                c[t].p=i;
                dn=max(dn,t);
            }
        }
        int t=0,s;
        for(int i=0; i<n; i++)
        {
                s=min(d[i],e[i]);
                t=max(t,s);
        }
        cout<<2*t-1<<endl;
    }
    return 0;
}
