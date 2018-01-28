#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct T
{
    int a,b,sum;
    char c[20];
} A[120];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->sum-b->sum)return a->sum-b->sum;
    else return strcmp(a->c,b->c);
}
int main()
{
    int num;
    //freopen("1.txt","r",stdin);
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int N,M,L,s;
        cin>>N>>M>>L;
        for(int k=0; k<L; k++)
        {
            char m[100],d;
            cin>>m;
            s=0;
            for(int j=0; m[j]; j++)
            {
                if(m[j]==':')
                {
                    A[k].c[j]='\0';
                    s=j;
                    break;
                }
                else A[k].c[j]=m[j];
            }
            sscanf(m+s+1,"%d%c%d",&A[k].a,&d,&A[k].b);
            int n=N;
            A[k].sum=0;
            while(n!=M)
            {
                if(n/2>=M)
                {
                    if(A[k].a*(n-n/2)<A[k].b)A[k].sum+=A[k].a*(n-n/2);
                    else A[k].sum+=A[k].b;
                }
                else {A[k].sum+=A[k].a*(n-M);break;}
                n/=2;
            }
        }
        qsort(A,L,sizeof(T),cmp);
        cout<<"Case "<<i+1<<endl;
        for(int k=0;k<L;k++)
            cout<<A[k].c<<' '<<A[k].sum<<endl;
    }
    return 0;
}
