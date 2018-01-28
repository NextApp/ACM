#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct T
{
    int x,y;
}A[100];
int cmp(const void*_a,const void*_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->x-b->x)return b->x-a->x;
    else return a->y-b->y;
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
        cin>>A[i].x>>A[i].y;
        qsort(A,n,sizeof(A[0]),cmp);
        int a[100];
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            if(A[i].x==A[i-1].x&&A[i].y==A[i-1].y)a[i]=a[i-1];
            else a[i]=a[i-1]+1;
        }
        int b=a[k-1],count=0;
        for(int i=0;i<n;i++)
        if(b==a[i])count++;
        cout<<count<<endl;
    }
    return 0;
}
