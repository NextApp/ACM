/*
ID: 15588661
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(const void *_a,const void *_b)
{
    int *a=(int *)_a;
    int *b=(int *)_b;
    return *a-*b;
}
int A[1000],B[1000];
int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int M,S,C;
    cin>>M>>S>>C;
    for(int i=0;i<C;i++)
    cin>>A[i];
    qsort(A,C,sizeof(int),cmp);
    for(int j=0;j<C-1;j++)
        B[j]=A[j+1]-A[j];
    qsort(B,C-1,sizeof(int),cmp);
    int sum=0;
    for(int j=0;j<C-M;j++)
    sum+=B[j];
    int d=M>C?C:M;//ע�⡣
    cout<<sum+d<<endl;
    return 0;
}
