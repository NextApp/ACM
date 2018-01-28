/*
ID:15588661
PROG:milk2
LANG:C++
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct T
{
    int x,y;
} A[8000];
int cmp(const void *_a,const void *_b)
{
    T *a=(T *)_a;
    T *b=(T *)_b;
    if(a->x - b->x)return a->x - b->x;
    else if(a->y - b->y)return a->y - b->y;
}
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int num;
    while(cin>>num)
    {
        for(int i=0; i<num; i++)
            cin>>A[i].x>>A[i].y;
        qsort(A,num,sizeof(A[0]),cmp);
        int m2=0,q1=A[0].x,q2=A[0].y;
        int l=q2-q1;
        for(int i=0; i<num; i++)
        {
            if(q2>=A[i].x&&q2<A[i].y)q2=A[i].y;
            else if(q2<A[i].x)
            {
                if(m2<A[i].x-q2)m2=A[i].x-q2;
                if(l<q2-q1)l=q2-q1;
                q1=A[i].x;
                q2=A[i].y;
            }
        }
        cout<<l<<' '<<m2<<endl;
    }
    return 0;
}
