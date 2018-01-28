#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100],b[100],c[100],d[100];
int main()
{
     freopen("1.txt","r",stdin);
    int n,id=1;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        int max1=0,ee=0,e[12];
        for(int i=0; i<n; i++)
        {
            memset(e,0,sizeof(e));
            e[a[i]]=e[b[i]]=e[c[i]]=1;
            for(int j=0; j<n; j++)
                if(!e[a[j]]&&!e[b[j]]&&!e[c[j]])
                {
                    e[a[j]]=e[b[j]]=e[c[j]]=1;
                    for(int k=0; k<n; k++)
                        if(!e[a[k]]&&!e[b[k]]&&!e[c[k]])
                        {
                            int m=d[i]+d[j]+d[k];
                            max1=m>max1?m:max1;
                        }
                }
        }
        cout<<"Case "<<id++<<": ";
        if(max1>0)cout<<max1<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
