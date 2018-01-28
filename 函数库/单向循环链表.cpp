#include<iostream>
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
        curPtr->n=i;
        curPtr->next=NULL;
        if(i==1)
            head=curPtr;
        else
            rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    return head;
}
num*ListChange(num *head,int id)
{
    if(id==1)return head;
    else
    {
        num*curPt,*prePt;
        curPt=head;
        head=head->next;
        free(curPt);
        curPt=head;
        while(curPt->next!=NULL)
        {
            prePt=curPt;
            curPt=curPt->next;
        }
        curPt->next=head;
        prePt=head->next;
        head->next=NULL;
        return ListChange(prePt,--id);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        num*head;
        head=ListCreate(n);
        head=ListChange(head,n);
        cout<<head->n<<endl;
    }
    return 0;
}
