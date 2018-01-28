#include<iostream>
#include<cstdio>
using namespace std;
int n,m,s;
int dfs(int a[])
{
    int c[8],ok=1;
    for(int i=0; i<n; i++)
        c[i]=a[i];
    for(int i=0; i<n-1; i++)
        if(a[i]>a[i+1])
        {
            ok=0,s=1;
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            dfs(a);
            for(int i=0; i<n; i++)
                a[i]=c[i];
        }
        if(ok)m++;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int id=1;
    while(cin>>n&&n)
    {
        int a[10];
        for(int i=0; i<n; i++)
            cin>>a[i];
            m=0,s=0;
            dfs(a);
            if(!s)m=0;
        cout<<"There are "<<m<<" swap maps for input data set "<<id++<<"."<<endl;
    }
    return 0;
}
