#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int N,a[50000],c[50000];
int bi_search(int n,int a)
{
    int f=1,h=n;
    while(f<=h)
    {
        int r=(f+h)/2;
        if(c[r]<a&&a<=c[r+1]&&r+1<=n)
        {
            if(a<c[r+1])c[r+1]=a;
            return r+1;
        }
        else if(c[r+1]<a)f=r+1;
        else h=r-1;
    }
    return -1;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0; i<N; i++)
            cin>>a[i];
        c[1]=a[0];
        int mm=1;
        for(int j=1; j<N; j++)
        {
            if(a[j]<c[1])c[1]=a[j];
            else
            {
                int s=bi_search(mm,a[j]);
                if(s==-1)c[++mm]=a[j];
            }
        }
        cout<<mm<<endl;
    }
    return 0;
}
