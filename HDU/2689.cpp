#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[7000],n;
int Lowbit(int x)
{
    return x&(-x);
}
int Sum(int end)
{
    int s=0;
    while(end)
    {
        s+=a[end];
        end-=Lowbit(end);
    }
    return s;
}
void Update(int end,int num)
{
    while(end<=n)
    {
        a[end]+=num;
        end+=Lowbit(end);
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int s;
            cin>>s;
            sum+=Sum(s);
            Update(s,1);
        }
        cout<<n*(n-1)/2-sum<<endl;
    }
    return 0;
}
