#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct T
{
    int a,b,n;
} m[1020];
int d[1020];
int cmp(const void *_a,const void*_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->b - b->b)return b->b - a->b;
    else return a->a - b->a;
}
void print(int s)
{
    for(int i=0; i<s; i++)
        if(m[i].a<m[s].a&&d[i]+1==d[s])
        {
            print(i);
    cout<<m[i].n<<endl;
            break;
        }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n=0;
    while(cin>>m[n].a>>m[n].b)
    {
        d[n]=1;
        m[n].n=n+1;
        n++;
    }
    qsort(m,n,sizeof(m[0]),cmp);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(m[i].a>m[j].a)d[i]=max(d[i],d[j]+1);
    int t=0,s;
    for(int i=0; i<n; i++)
        if(d[i]>t)
        {
            t=d[i];
            s=i;
        }
    cout<<t<<endl;
    print(s);
    cout<<m[s].n<<endl;
    return 0;
}
