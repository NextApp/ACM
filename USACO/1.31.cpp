/*
ID: 15588661
PROG: milk
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct T
{
    int x,y;
}a[10000];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return a->x - b->x;
}
int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    cin>>a[i].x>>a[i].y;
    qsort(a,M,sizeof(T),cmp);
    int sum=0,s=0,j;
    for(j=0;j<M;j++)
    if(sum+a[j].y<N)
    {
        sum+=a[j].y;
        s+=a[j].x*a[j].y;
    }
    else break;
    s+=(N-sum)*a[j].x;
    cout<<s<<endl;
    return 0;
}
