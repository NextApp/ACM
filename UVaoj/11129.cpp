#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
#include<algorithm>
using namespace std;
int M[11000];
typedef struct T
{
    int data;
    struct T*next;
} node;
node *newnode()
{
    node*u=(node*)malloc(sizeof(node));
    if(u!=NULL)u->next=NULL;
    return u;
}
T*bulid(int n)
{
    int i=2;
    node *root=newnode(),*u=newnode();
    root->data=0;
    u->data=1;
    root->next=u;
    node *r=root;
    while(i<n)
    {
        r=root;
        u=root->next;
        while(u!=NULL)
        {

            int o=r->data > u->data? 2*r->data - u->data:2*u->data - r->data;
            if(!M[o]&&o<n)
            {
                node*s=newnode();
                r->next=s;
                s->next=u;
                s->data=o;
                M[o]=1;
                i++;
            }
            if(i>=n)break;
            r=u;
            u=u->next;
        }
    }
    return root;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)return 0;
        else
        {
            memset(M,0,sizeof(M));
            node*u=bulid(n);
            cout<<n<<": ";
            while(u->next!=NULL)
            {
                cout<<u->data<<' ';
                u=u->next;
            }
            cout<<u->data<<endl;
        }
    }
    return 0;
}
