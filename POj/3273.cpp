#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[105000],N,M,m;
int Judge(int n)
{
    if(n<m)return 0;
    int s=0,num=1;
    for(int i=0; i<N; i++)
        if(s+a[i]<=n)s+=a[i];
        else if(s+a[i]>n)
        {
            s=a[i];
            num++;
        }
    if(num<=M)return 1;
    else  return 0;
}
int b_search(int s,int e)
{
    s-=1,e++;
    while(s<=e)
    {
        int k=(s+e)/2;
        int f1=Judge(k),f2=Judge(k+1);
        if(!f1&&f2)
        {
            cout<<k+1<<endl;
            break;
        }
        else if(f1&&f2)e=k;
        else s=k+1;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>N>>M)
    {
        int sum=0;
        m=0;
        for(int i=0; i<N; i++)
        {
            cin>>a[i];
            m=max(m,a[i]);
            sum+=a[i];
        }
        b_search(m,sum);
    }
    return 0;
}
