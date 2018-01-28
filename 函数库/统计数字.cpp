#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,n_len,N[20];
void change(int n)
{
    n_len=1;
    int a[12];
    while(n/10)
    {
        a[n_len++]=n%10;
        n/=10;
    }
    a[n_len]=n;
    for(int i=n_len; i>=1; i--)
        N[n_len-i+1]=a[i];
}
int cal(int p,int a,int ok)
{
    int sum=0;
    for(int i=1; i<=n_len; i++)
    {
        if(i==p)
        {
            if(ok>0&&a)sum++;
            if(!ok&&!a)sum--;
            continue;
        }
        if(ok)
        {
            if(i<p)sum=sum*10+N[i];
            else sum=sum*10;
        }
        else sum=sum*10+N[i];
    }
    if(!ok)sum++;
    return sum;
}
int result[12];
void tongji(int n)
{
    change(n);
    memset(result,0,sizeof(result));
    for(int i=0; i<=9; i++)
        for(int j=1; j<=n_len; j++)
            result[i]+=cal(j,i,N[j]-i);
}
int main()
{
     freopen("1.txt","r",stdin);
     freopen("out.txt","w",stdout);
    while(cin>>n)
    {
        tongji(n);
        for(int i=0; i<10; i++)
            cout<<result[i]<<endl;
    }
    return 0;
}
