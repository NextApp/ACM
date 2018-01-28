#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char a[2000];
struct T
{
    int m;
    char a;
}A[40];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(b->m - a->m)return b->m-a->m;
    else return a->a-b->a;
}
int main()
{
   // freopen("2.txt","r",stdin);
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<26;i++){A[i].m=0;A[i].a='A'+i;}
    for(int i=0; i<n; i++)
    {
        gets(a);
        for(int j=0; a[j]; j++)
            if(a[j]>='a'&&a[j]<='z')
                A[a[j]-'a'].m++;
            else if(a[j]<='Z'&&a[j]>='A')
                A[a[j]-'A'].m++;
    }
    qsort(A,26,sizeof(T),cmp);
    for(int i=0; i<26; i++)
        if(A[i].m)cout<<A[i].a<<' '<<A[i].m<<endl;
    return 0;
}
