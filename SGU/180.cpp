#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100000],b[100000],n;
long long cnt=0;
void merge_sort(int *A,int x,int y,int *T)
{
    if(y-x>1)
    {
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);
        while(p<m||q<y)
        {
            if(q>=y||(p<m&&A[p]<=A[q]))
            T[i++]=A[p++];
            else {T[i++]=A[q++];cnt+=m-p;}
        }
        for(i=x;i<y;i++)A[i]=T[i];
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        cin>>a[i];
        cnt=0;
        merge_sort(a,0,n,b);
        cout<<cnt<<endl;
    }
    return 0;
}
