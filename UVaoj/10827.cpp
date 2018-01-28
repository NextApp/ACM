#include<iostream>
#include<cstdio>
using namespace std;
int a[108][108],M[208][208],n,Max=-108;
int ChangeMatrix()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    for(int i=0; i<n/2; i++)
        for(int j=0; j<n; j++)
        {
            int temp=a[i][j];
            a[i][j]=a[n-i-1][j];
            a[n-i-1][j]=temp;
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(!j)M[i][j]=a[i][j];
            else M[i][j]=a[i][j]+M[i][j-1];
            M[i+n][j]=M[i][j];
        }
}
void Maxsum()
{
    for(int j=-1; j<n-1; j++)
        for(int s=j+1; s<n; s++)
            for(int i=0; i<n; i++)
            {
                int sum=0,l=i;
                for(int k=i; k<2*n; k++)
                {
                    if(j!=-1)sum+=M[k][s]-M[k][j];
                    else sum+=M[k][s];
                    Max=sum>Max?sum:Max;
                    if(sum<=0)
                    {
                        l=k+1;
                        sum=0;
                    }
                    if(k-l>=n-1)break;
                }
            }
}
int main()
{
    freopen("1.txt","r",stdin);
    int num;
    cin>>num;
    for(int g=0; g<num; g++)
    {
        cin>>n;
        Max=-108;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                if(!j)M[i][j]=a[i][j];
                else M[i][j]=a[i][j]+M[i][j-1];
                M[i+n][j]=M[i][j];
            }
        }
        Maxsum();
        ChangeMatrix();
        Maxsum();
        cout<<Max<<endl;
    }
    return 0;
}
