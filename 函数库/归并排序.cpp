#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500
using namespace std;
int a[N],b[N];
void guibing(int l,int r)
{
    if(r-l<1)return ;
    int k=(l+r)/2;
    guibing(l,k);
    guibing(k+1,r);
    int m=0,i=l,j=k+1;
    while(i<=k||j<=r)
    {
        if(i<=k&&j<=r)
        {
            if(a[i]<a[j])b[m++]=a[i++];
            else b[m++]=a[j++];
        }
        else
        {
            if(i<=k)b[m++]=a[i++];
            if(j<=r)b[m++]=a[j++];
        }
    }
    for(int i=l;i<=r;i++)
        a[i]=b[i-l];
}
int main()
{
    freopen("1.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        cin>>a[i];
        guibing(0,n-1);
        for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    }
    return 0;
}
