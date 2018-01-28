#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a[110],n,num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        memset(a,1,sizeof(a));
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j+=i)
            {
                if(!a[j])a[j]=1;
                else a[j]=0;
            }
        int count=0;
        for(int i=1;i<=n;i++)
        if(!a[i])count++;
        cout<<count<<endl;
    }
    return 0;
}
