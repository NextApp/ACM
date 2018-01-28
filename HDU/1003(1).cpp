#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x1,y1,mm;
int maxsum(int *A,int x,int y)
{
    int i,m,v,L,R,max;
    if(y-x==1)
    {
        if(mm<A[x])
        {
            mm=A[x];
            x1=x;
            y1=x;
        }
        return A[x];
    }
    m=x+(y-x)/2;
    int l=maxsum(A,x,m),r=maxsum(A,m,y);
    max=l>r?l:r;
    v=0;
    L=A[m-1];
    int x2=m-1,y2=m;
    for(i=m-1; i>=x; i--)
    {
        v+=A[i];
        if(v>=L)
        {
            L=v;
            x2=i;
        }
    }
    v=0;
    R=A[m];
    for(i=m; i<y; i++)
    {
        v+=A[i];
        if(v>R)
        {
            R=v;
            y2=i;
        }
    }
    if(max>L+R)
    {
        if(mm<max)mm=max;
        return max;
    }
    else
    {
        if(mm<L+R)
        {
            mm=L+R;
            x1=x2;
            y1=y2;
        }
        return L+R;
    }
}
int a[120000];
int main()
{
    int num,n;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        mm=-120000000;
        if(i)cout<<endl;
        cout<<"Case "<<i+1<<":"<<endl;
        for(int j=0; j<n; j++)
            cin>>a[j];
        cout<<maxsum(a,0,n);
        cout<<' '<<x1+1<<' '<<y1+1<<endl;
    }
    return 0;
}
