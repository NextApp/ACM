#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100],b[100],c[100],d[100],m[12],ms=0,n,id=1;
int dfs(int cur,int s,int ss)
{
    if(s==3)ms=ss>ms?ss:ms;
    else
    {
        for(int i=0;i<n;i++)
        if(!m[a[i]]&&!m[b[i]]&&!m[c[i]]){
            m[a[i]]=m[b[i]]=m[c[i]]=1;
            dfs(cur+1,s+1,ss+d[i]);
            m[a[i]]=m[b[i]]=m[c[i]]=0;
        }
    }
}
int main()
{
     freopen("1.txt","r",stdin);
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
            cin>>a[i]>>b[i]>>c[i]>>d[i];
            memset(m,0,sizeof(m));
            ms=0;
            dfs(0,0,0);
        cout<<"Case "<<id++<<": ";
        if(ms>0)cout<<ms<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
