#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Point
{
    int x,y;
} A[10000];
int cmp(const void *_a,const void *_b)
{
    Point *a=(Point *)_a;
    Point *b=(Point *)_b;
    if(a->x-b->x)return a->x - b->x;
    else return a->y - b->y;
}
int main()
{
    // freopen("1.txt","r",stdin);
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m)break;
        else
        {
            int mm=100000000,mx=0;
            for(int i=0; i<n*n; i++)
            {
                cin>>A[i].x>>A[i].y;
                if(A[i].y<mm)mm=A[i].y;
                if(A[i].y>mx)mx=A[i].y;
            }
            qsort(A,n*n,sizeof(A[0]),cmp);
            int sum=0,k=0,min=100000000;
            for(int i=mm; i+n-1<=m&&i<=mx; i++)
            {
                sum=0;
                for(int j=0; j<n*n; j++)
                {
                    if(!(j%n))k=0;
                    if(A[j].y>i+k)sum+=A[j].y-i-k;
                    else sum+=i+k-A[j].y;
                    k++;
                }
                if(min>sum)min=sum;
            }
            cout<<min<<endl;
        }
    }
    return 0;
}
