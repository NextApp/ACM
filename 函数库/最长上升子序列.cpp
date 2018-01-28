#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[100],d[100];
void print(int i)
{
    for(int j=0; j<i; j++)
        if(a[i]>a[j]&&d[i]==d[j]+1)
        {
            cout<<' '<<j+1;
            print(j);
            break;
        }
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            d[i]=1;
        }
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(a[i]>a[j])d[i]=max(d[j]+1,d[i]);
        int t=0,s;
        for(int i=0; i<n; i++)
        if(d[i]>t)
        t=d[i],s=i;
        cout<<s+1;
        print(s);
        cout<<endl;
    }
    return 0;
}
