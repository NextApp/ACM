#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double a[10];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
    {
        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)break;
        else
        {
        double s=0,min=a[0],max=a[0];
        for(int i=0; i<6; i++)
        {
            s+=a[i];
            if(min>a[i])min=a[i];
            if(max<a[i])max=a[i];
        }
        s-=min+max;
        s/=4.0;
        cout<<s<<endl;
        }
    }
    return 0;
}
