#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[120][120],sum[120][120];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                if(!j)sum[i][j]=a[i][j];
                else sum[i][j]=sum[i][j-1]+a[i][j];
            }
        int mm=-11110;
        for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            int s=0;
            for(int t=0;t<n;t++)
            {
                int m=sum[t][j]-sum[t][i]+a[t][i];
                if(s+m>=0)
                {
                    s+=m;
                    mm=max(s,mm);
                }
                else s=0;
            }
        }
        cout<<mm<<endl;
    }
    return 0;
}
