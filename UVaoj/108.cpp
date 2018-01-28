#include<iostream>
#include<cstdio>
using namespace std;
int a[108][108],M[108][108],Max=-108;
int main()
{
    int n;
   // freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
            if(!j)M[i][j]=a[i][j];
            else M[i][j]=a[i][j]+M[i][j-1];
        }
    }
    int sum;
    for(int j=0; j<n; j++)
        for(int k=j; k<n; k++)
        {
            sum=0;
            for(int i=0; i<n; i++)
            {
                sum+=M[i][k]-M[i][j];
                if(sum>0)Max=sum>Max?sum:Max;
                else sum=0;
            }
        }
    for(int k=0; k<n; k++)
    {
        sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=M[i][k];
            if(sum>0)Max=sum>Max?sum:Max;
            else sum=0;
        }
    }
    cout<<Max<<endl;
    return 0;
}
