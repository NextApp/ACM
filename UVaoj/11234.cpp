#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
using namespace std;
char a[10100];
typedef struct T
{
    char data;
    T*left,*right;
}node;
node*newnode()
{
    node *u=(node*)malloc(sizeof(node));
    if(u!=NULL)
    {
        u->left=u->right=NULL;
    }
    return u;
}
node*q[10100];
void bfs()
{
    int front =0,rear=1,k=0;
    while(front<rear)
    {
        node*u=q[front++];
        if(u->right!=NULL)q[rear++]=u->right;
        if(u->left!=NULL)q[rear++]=u->left;
        a[k++]=u->data;
    }
    for(int i=k-1;i>=0;i--)cout<<a[i];
    cout<<endl;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int k=0;
        for(int i=0;a[i];i++)
        {
            if(a[i]<='z'&&a[i]>='a')
            {
                node*u=newnode();
                u->data=a[i];
                q[k++]=u;
            }
            else
            {
                node*u=newnode();
                u->data=a[i];
                u->right=q[k-2];
                u->left=q[k-1];
                q[k-2]=u;
                k--;
            }
        }
        bfs();
    }
    return 0;
}
