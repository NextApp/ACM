#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double Min;
int num;
struct T
{
    double a,b;
}A[12200];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return a->a > b->a?1:-1;
}
double linelen(int a,int b)
{
    return sqrt((A[a].a-A[b].a)*(A[a].a-A[b].a)+(A[a].b-A[b].b)*(A[a].b-A[b].b));
}
double minline(int x,int y)
{
    double l1,l2,min0;
    int mid;
    if(y==x)return 100000;
    if(y-x==1)return linelen(x,y);
    mid=(y+x)/2;
    l1=minline(x,mid);
    l2=minline(mid,y);
    min0=l1<l2?l1:l2;
    Min=min0<Min?min0:Min;
    for(int i=mid-1;i>=x&&A[mid].a-A[i].a<=Min;i--)
    for(int j=mid+1;j<=y&&A[j].a-A[mid].a<=Min;j++)
    {
        double len=linelen(i,j);
        Min=len>Min?Min:len;
    }
    return Min;
}
int main()
{
   // freopen("2.txt","r",stdin);
    while(cin>>num)
    {
        if(!num)break;
        else
        {
            for(int i=0; i<num; i++)
                cin>>A[i].a>>A[i].b;
            qsort(A,num,sizeof(T),cmp);
            Min=20000;
            minline(0,num-1);
            if(Min>10000)cout<<"INFINITY"<<endl;
            else printf("%.4lf\n",Min);
        }
    }
    return 0;
}
