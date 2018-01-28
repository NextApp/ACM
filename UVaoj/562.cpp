#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num,a[120],d[51000];
int main()
{
    //
    freopen("1.txt","r",stdin);
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int m,sum=0;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        memset(d,0,sizeof(d));
        for(int i=0; i<m; i++)
            for(int j=sum/2; j>=0; j--)
                if(j-a[i]>=0)d[j]=max(d[j],d[j-a[i]]+a[i]);
        cout<<sum-d[sum/2]*2<<endl;
    }
    return 0;
}
