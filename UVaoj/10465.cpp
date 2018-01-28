#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mm,mn;
int ddd(int t)
{
    for(int i=t/mm; i>=0; i--)
        if((t-i*mm)%mn==0)
            return (t-i*mm)/mn+i;
    return -1;
}
int main()
{
    freopen("1.txt","r",stdin);
    int m,n,t;
    while(cin>>m>>n>>t)
    {
        mm=m,mn=n;
        if(m>n)mm=n,mn=m;
        int count=ddd(t);
        if(count!=-1)cout<<count<<endl;
        else
        {
            int s=t-1;
            while(1)
            {
                count=ddd(s);
                if(count>=0)break;
                s--;
            }
            cout<<count<<' '<<t-s<<endl;
        }
    }
    return 0;
}
