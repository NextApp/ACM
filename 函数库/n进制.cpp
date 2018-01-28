#include<iostream>
#include<cstring>
using namespace std;
int swap(int a[],int len)
{
    int j=len-1,temp;
    for(int i=0; i<len/2; i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int main()
{
    int a[1000];
    int b,k;
    while(cin>>b>>k)
    {
        int i=0;
        while(b>=k)
        {
            a[i++]=b%k;
            b/=k;
        }
        int count=i+1;
        a[i]=b;
        swap(a,count);
        for(int i=0; i<count; i++)
            cout<<a[i];

        cout<<endl;
    }
}
