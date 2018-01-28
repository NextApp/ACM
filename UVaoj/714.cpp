#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,k,a[530];
int posion[505];
long long MAX;
int judge(long long M)
{
    long long l=0,num=0;
    for(int i=m-1; i>=0; i--)
    {
        posion[num]=0;
        l+=a[i];
        if(l>M)
        {
            posion[num++]=i+1;
            l=a[i];
        }
        if(a[i]>M)return -1;
    }
    if(num>k-1)return -1;
    else return num;
}
int BinarySearch()
{
    long long  aa=0,b=MAX;
    int kk;
    while(b-aa>1)
    {
        kk=(b+aa)/2;
        int l=judge(kk);
        if(l!=-1)b=kk;
        else aa=kk;
    }
    int l=judge(b),temp;
    for(int i=0,j=l-1;i<l/2;i++,j--)//交换
    {
        temp=posion[i];
        posion[i]=posion[j];
        posion[j]=temp;
    }
    int num=0,t=k-l-1;
    for(int i=0; i<m; i++)
    {
        if(i)cout<<' ';
        if(i==posion[num]&&num<l)
        {
            cout<<"/ ";
            num++;
        }
        else if(t&&i)
        {
            cout<<"/ ";
            t--;
        }
        cout<<a[i];
    }
    cout<<endl;
}
int main()
{
    int num;
   // freopen("1.txt","r",stdin);
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>m>>k;
        MAX=0;
        for(int j=0; j<m; j++)
        {
            cin>>a[j];
            MAX+=a[j];
        }
        BinarySearch();
    }
    return 0;
}
