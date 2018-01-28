#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
typedef struct num
{
    int n;
    num *next;
};
num *ListCreate(int n)
{
    num *head=NULL,*curPtr,*rearPtr;
    int i;
    for(int i=1; i<=n; i++)
    {
        curPtr=(num *)malloc(sizeof(num));
        cin>>curPtr->n;
        curPtr->next=NULL;
        if(i==1)
            head=curPtr;
        else
            rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    return head;
}
num*ListLeft(num *head)
{
    num*curPt,*prePt;
    curPt=head;
    while(curPt->next!=NULL)
    {
        prePt=curPt;
        curPt=curPt->next;
    }
    curPt->next=head;
    prePt=head->next;
    head->next=NULL;
    return prePt;
}
num*listwight(num*head)
{
    num*curPt,*prePt;
    curPt=head;
    while(curPt->next!=NULL)
    {
        prePt=curPt;
        curPt=curPt->next;
    }
    curPt->next=head;
    prePt->next=NULL;
    return curPt;
}
num*listchange(num*head,int i,int j)
{
    int k=1;
    num*curPt,*prePt,*p1,*p2;
    curPt=head;
    while(curPt!=NULL&&k!=i)
    {
        prePt=curPt;
        curPt=curPt->next;
        k++;
    }
    p1=curPt;
    while(curPt!=NULL&&k!=j)
    {
        prePt=curPt;
        curPt=curPt->next;
        k++;
    }
    p2=curPt;
    int temp=p1->n;
    p1->n=p2->n;
    p2->n=temp;
    return head;
}
int listcheck(num*head)
{
    num *curPt,*prePt;
    int k=1;
    curPt=head;
    while(curPt!=NULL)
    {
        if(curPt->n!=k++)return 0;
        prePt=curPt;
        curPt=curPt->next;
    }
    return 1;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            int i,j;
            cin>>i>>j;
            num*head;
            head=ListCreate(n);
            head=ListLeft(head);
            head=listchange(head,i,j);
            head=listwight(head);
            if(listcheck(head))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
