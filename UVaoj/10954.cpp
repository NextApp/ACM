#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[11000];
int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            for(int i=0; i<n; i++)cin>>a[i];
            sort(a,a+n);
            int sum=0,tem,i=0,j;
            while(1)
            {
                if(i+2>n)break;
                tem=a[i]+a[i+1];
                for(j=i+2; j<n; j++)
                    if(a[j]>tem)break;
                for(int k=n; k>=j; k--)a[k+1]=a[k];
                a[j]=tem;
                n++;
                i+=2;
                sum+=tem;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
