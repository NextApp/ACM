#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<algorithm>
#define MAX 1000003
#define N 1073741824
using namespace std;
int a[1200],vis[1001000];
struct T
{
    int a,b;
    T*next;
} M[1001000];
int hash(int m)
{
    return m%MAX;
}
T*newnode()
{
    T*u=(T*)malloc(sizeof(T));
    u->next=NULL;
    return u;
}
int compare(int a,int b,int c,int d)
{
    if(a!=c&&c!=b&&a!=d&&b!=d&&a+b==c-d)return 1;
    return 0;
}
int insert(int a,int b)
{
    int m=hash(a+b+N);
    T*u=newnode();
    u->a=a;
    u->b=b;
    if(!vis[m])
    {
        M[m].next=u;
        vis[m]=1;
    }
    else
    {
        u->next=M[m].next;
        M[m].next=u;
    }
}
int search(int a,int b)
{
    int m=hash(a-b+N);
    if(vis[m])
    {
        T*u=M[m].next;
        while(u!=NULL)
        {
            if(compare(u->a,u->b,a,b))return 1;
            u=u->next;
        }
    }
    return 0;
}
int main()
{
    int n;
    //freopen("1.txt","r",stdin);
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)cin>>a[i];
        sort(a,a+n);
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                insert(a[i],a[j]);
        int d=-N-1;
        for(int i=n-1; i>0; i--)
            for(int j=i-1; j>=0; j--)
                if(search(a[i],a[j]))d=a[i]>d?a[i]:d;
        if(d>-N-1)cout<<d<<endl;
        else cout<<"no solution"<<endl;
    }
    return 0;

}
