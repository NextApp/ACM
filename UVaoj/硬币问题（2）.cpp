#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[10],S,n,d[1000];
void print_ans(int S)
{
    for(int i=0;i<n;i++)
    if(S>=a[i]&&d[S]==d[S-a[i]]+1)
    {
        printf("%d ",a[i]);
        print_ans(S-a[i]);
        break;
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>n>>S)
    {
        for(int i=0; i<n; i++)
            cin>>a[i];
        memset(d,-1,sizeof(d));
        for(int j=1; j<=S; j++)
        {
            int t=-1;
            for(int i=0; i<n; i++)
            {
                if(j==a[i])t=max(t,1);
                if(j-a[i]>0&&d[j-a[i]]>0)t=max(t,d[j-a[i]]+1);
            }
            d[j]=t;
        }
        for(int i=1;i<=S;i++)d[i]=-100;
        d[0]=0;
        for(int j=1;j<=S;j++)
        {
            for(int i=0;i<n;i++)
            if(j>=a[i])d[j]=max(d[j],d[j-a[i]]+1);
        }
        cout<<d[S]<<endl;
        print_ans(S);
        cout<<endl;
    }
    return 0;
}
