#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10020];
int main()
{
    //freopen("2.txt","r",stdin);
    int n,id=0;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            if(id)cout<<endl;
            id++;
            for(int i=0; i<n; i++)
                cin>>a[i];
            sort(a,a+n);
            int maxnum=1,k=1;
            for(int i=0; i<n-1; i++)
            {
                if(a[i]==a[i+1])k++;
                else
                {
                    maxnum=maxnum>k?maxnum:k;
                    k=1;
                }
            }
            maxnum=maxnum>k?maxnum:k;
            cout<<maxnum<<endl;
            for(int s=0; s<maxnum; s++)
            {
                for(int i=s;i<n; i+=maxnum)
                    if(i+maxnum<n)cout<<a[i]<<' ';
                    else cout<<a[i]<<endl;
            }
        }
    }
    return 0;
}
