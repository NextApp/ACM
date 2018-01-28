#include<iostream>
#include<cstdio>
using namespace std;
int a[200][200];
int main()
{
    int numcase;
    cin>>numcase;
    for(int i=0;i<numcase;i++)
    {
        int n,Max=-108;
        cin>>n;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            a[i+n][j+n]=a[i][j+n]=a[i+n][j]=a[i][j];
        }
        int c[120],b[120];
        for(int k=0;k<n;k++)
        for(int l=0;l<n;l++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            c[j]=a[i+k][j+l];
            if(j)c[j]+=c[j-1];
            if(!i)b[j]=c[j];
            else b[j]+=c[j];
            Max=Max>b[j]?Max:b[j];
        }
        cout<<Max<<endl;
    }
    return 0;
}
