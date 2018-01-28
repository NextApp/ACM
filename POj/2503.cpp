#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 110000
using namespace std;
struct T
{
    char a[30],b[30];
} M[N];
char m[1000];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return strcmp(a->b,b->b);
}
void b_search(int n)
{
    int a=0,b=n-1;
    while(a<=b)
    {
        int k=(a+b)/2;
        int c=strcmp(m,M[k].b);
        if(!c)
        {
            cout<<M[k].a<<endl;
            return ;
        }
        else if(c>0)a=k+1;
        else b=k-1;
    }
    cout<<"eh"<<endl;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int i=0;
    while(gets(m)!=NULL)
    {
        if(m[0]=='\0')break;
        else
        {
            int k;
            for(k=0; m[k]!=' '; k++);
            m[k]='\0';
            strcpy(M[i].a,m);
            strcpy(M[i++].b,m+k+1);
        }
    }
    qsort(M,i,sizeof(M[0]),cmp);
    while(cin>>m)
    {
        b_search(i);
    }
    return 0;
}
