#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    cin>>num;
    while(num--)
    {
        int n;
        cin>>n;
        int i=9,a[100],k=0;
        if(!n)
        {
            cout<<'0'<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        while(i>1)
        {
            while(!(n%i))
            {
                n/=i;
                a[k++]=i;
            }
            i--;
        }
        if(n==1)
        {
            sort(a,a+k);
            for(int i=0; i<k; i++)cout<<a[i];
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
