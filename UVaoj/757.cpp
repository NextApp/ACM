#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct T
{
    int data,di,time;
} a[30];
int n,h,Data[30],D[30],T[30],t[30];
int search(int nn)
{
    int m=0,max=a[0].data;
    for(int i=1; i<=nn; i++)
        if(a[i].data>max)m=i,max=a[i].data;
    return m;
}
int maxsum(int nn)
{
    int s,hh=h*12-D[nn-1],sum=0;
    for(int i=0; i<=nn; i++)a[i].data=Data[i];
    memset(t,0,sizeof(t));
    while(hh>0)
    {
        s=search(nn);
        if(a[s].data>0)
        {
            sum+=a[s].data;
            a[s].data-=a[s].di;
            t[s]++;
        }
        else t[0]++;
        hh--;
    }
    return sum;
}
int compare()
{
    for(int i=0; i<n; i++)
        if(T[i]>t[i])return 1;
        else if(T[i]<t[i])return 0;
}
int MaxFish()
{
    int max=0,o,data=Data[0];
    memset(T,0,sizeof(T));
    o=T[0]=h*12;
    while(o--)
    {
        if(data>0)max+=data;
        else break;
        data-=a[0].di;
    }
    for(int i=1; i<n; i++)
    {
        int s=maxsum(i);
        if(s>max)for(int j=0; j<n; j++){T[j]=t[j];max=s;}
        else if(s==max&&!compare())for(int j=0; j<n; j++)T[j]=t[j];
    }
    return max;
}
int main()
{
   // freopen("1.txt","r",stdin);
   int id=0;
    while(cin>>n)
    {
        if(!n)return 0;
        else
        {
            if(id)cout<<endl;
            id++;
            cin>>h;
            int hh;
            for(int i=0; i<n; i++)cin>>Data[i];
            for(int i=0; i<n; i++)cin>>a[i].di;
            for(int i=0; i<n-1; i++)
            {
                cin>>hh;
                if(!i)D[i]=hh;
                else  D[i]=D[i-1]+hh;
            }
            int max=MaxFish();
            for(int i=0; i<n-1; i++)
                cout<<T[i]*5<<", ";
            cout<<T[n-1]*5<<endl;
            cout<<"Number of fish expected: "<<max<<endl;
        }
    }
    return 0;
}
