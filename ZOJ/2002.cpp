#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[560],MA,t;
int P(int x)
{
    if(x<t)return 0;
    int num=1,sum=0;
    for(int i=0; i<n; i++)
        if(a[i]+sum<=x)sum+=a[i];
        else
        {
            num++;
            sum=a[i];
        }
    if(num<=m)return 1;
    else return 0;
}
int b_search(int f,int h)
{
    int x=f,y=h;
    while(x<=y)
    {
        int s=(x+y)/2;
        int e=P(s),r=P(s-1);
        if(e&&!r)
        {
            return s;
        }
        else if(r)y=s-1;
        else x=s+1;
    }

}
int main()
{
  // freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        t=0;
        MA=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            t=max(a[i],t);
            MA+=a[i];
        }
        int sum=b_search(t,MA);
        int s=0;
        int v[1000];
        int nu=m-1;
        memset(v,0,sizeof(v));
        for(int j=n-1; j>=0; j--)
            if(s+a[j]<=sum)
            {
                s+=a[j];
            }
            else
            {
                s=a[j];
                v[j+1]=1;
                nu--;
            }
        for(int j=0; j<n; j++)
        {
            if((j&&nu>0)||v[j])
            {
                cout<<"/ ";
                if(!v[j])nu--;
            }
            if(j==n-1)cout<<a[n-1]<<endl;
            else cout<<a[j]<<' ';
        }
    }
    return 0;
}
