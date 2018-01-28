#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int cmp_int(const void *_a,const void *_b)
{
    int*a=(int*)_a;
    int*b=(int*)_b;
    return *a-*b;
}
int main()
{
    int len,n;
    char a[200][200];
    int b[220],c[220];
    cin>>len>>n;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        for(int j=0; j<len-1; j++)
        {
            for(int k=j+1; k<len; k++)
                if(a[i][j]>a[i][k])
                {
                    b[i]++;
                    c[i]++;
                }
        }
    }
    qsort(c,n,sizeof(int),cmp_int);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(c[i]==b[j])
            {
                b[j]=-1;
                cout<<a[j]<<endl;
                break;
            }
    }
    return 0;
}
