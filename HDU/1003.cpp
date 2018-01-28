#include<iostream>
#include<cstdio>
using namespace std;
int a[122000],b[122000];
int main()
{
    int num,n,id=0;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        int sum=0;
        for(int j=0; j<n; j++)
        {
            cin>>a[j];
            sum+=a[j];
            b[j]=sum;
        }
        int ss=-100003020,o1,o2;
        for(int j=-1; j<n-1; j++)
            for(int k=j+1; k<n; k++)
            {
                if(j<0)
                {
                    if(b[k]>ss)
                    {
                        ss=b[k];
                        o1=j;
                        o2=k;
                    }
                }
                else if(b[k]-b[j]>ss)
                {
                    ss=b[k]-b[j];
                    o1=j;
                    o2=k;
                }
            }
        if(id)cout<<endl;
        cout<<"Case "<<++id<<":"<<endl;
        cout<<ss<<' '<<o1+2<<' '<<o2+1<<endl;
    }
    return 0;
}
