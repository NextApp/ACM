#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Line
{
    char f[20],e[20];
    double a,b,c,d;
} A[100005];
int q[100005];
int cmp(const void *_a,const void *_b)
{
    Line *a=(Line*)_a;
    Line *b=(Line*)_b;
    if(a->c > b->c)return 1;
    else if(a->c < b->c)return -1;
    else if(b->d > a->d)return 1;
    else return -1;
}
int main()
{
    int num;
   //  freopen("2.txt","r",stdin);
    cin>>num;
    while(num--)
    {
        int M;
        int i=0;
        cin>>M;
        while(cin>>A[i].e>>A[i].f)
        {
            int ok=0;
            sscanf(A[i].e,"%lf",&A[i].a);
            sscanf(A[i].f,"%lf",&A[i].b);
            if(!A[i].a&&!A[i].b)break;
            else
            {
                if(A[i].a<=0)A[i].c=0;
                else if(A[i].a<=M)A[i].c=A[i].a;
                else ok=1;
                if(A[i].b>M)A[i].d=M;
                else if(A[i].b<=0)ok=1;
                else A[i].d=A[i].b;
                if(!ok)i++;
            }
        }
        qsort(A,i,sizeof(Line),cmp);
        int k=0,OK=1;
        if(!i)OK=0;
        else
        {
            if(A[0].c>0)OK=0;
            else
            {
                q[k]=0;
                int j=1,m=0,oo=0;
                double max=0;
                while(j<i)
                {
                    if(A[j].c<=A[q[k]].d&&A[j].d>A[q[k]].d)
                    {
                        if(max<A[j].d-A[q[k]].d)
                        {
                            m=j;oo=1;
                            max=A[j].d-A[q[k]].d;
                        }
                    }
                    else if(A[j].c>A[q[k]].d&&oo)
                    {
                        q[++k]=m;
                        oo=0;
                        max=0;
                        j--;
                    }
                    j++;
                }
                if(oo)q[++k]=m;
                if(A[q[k]].d<M)OK=0;
            }
        }
        if(OK)
        {
            cout<<k+1<<endl;
            for(int j=0; j<=k; j++)
                cout<<A[q[j]].e<<' '<<A[q[j]].f<<endl;
        }
        else cout<<0<<endl;
        if(num)cout<<endl;
    }
    return 0;
}
