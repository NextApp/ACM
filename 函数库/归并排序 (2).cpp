#include<iostream>
#include<cstring>
#include<cstdio>
#include<malloc.h>
#define N 500
using namespace std;
struct T
{
    int data;
    T*next;
};
T*newnode()
{
    T*u=(T*)malloc(sizeof(T));
    if(u!=NULL)
    {
        u->next=NULL;
        return u;
    }
}
int b[N];
void guibing(T*u,int l,int r)
{
    if(r-l<1)return ;
    int k=(l+r)>>1;
    guibing(u,l,k);
    guibing(u,k+1,r);
    int m=0,t1=0,t2=0;
    T*u1=u,*u2=u;
    while(t1<l)u1=u1->next,t1++;
    while(t2<k+1)u2=u2->next,t2++;
    T*u3=u1;
    t1=l,t2=k+1;
    while(t1<=k||t2<=r)
    {
        if(t1<=k&&t2<=r)
        {
            if(u1->data<u2->data)
            {
                b[m++]=u1->data;
                u1=u1->next,t1++;
            }
            else
            {
                b[m++]=u2->data;
                u2=u2->next,t2++;
            }
        }
        else
        {
            while(t1<=k)
            {
                b[m++]=u1->data;
                u1=u1->next,t1++;
            }
            while(t2<=r)
            {
                b[m++]=u2->data;
                u2=u2->next,t2++;
            }
        }
    }
    int t=l;
    while(t<=r)
    {
        u3->data=b[t++-l];
        u3=u3->next;
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        T*u=newnode(),*root;
        root=u;
        for(int i=0; i<n; i++)
        {
            cin>>u->data;
            u->next=newnode();
            u=u->next;
        }
        u=root;
        guibing(u,0,n-1);
        u=root;
        while(u->next!=NULL)
        {
            cout<<u->data<<endl;
            u=u->next;
        }
    }
    return 0;
}
