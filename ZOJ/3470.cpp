#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1)cout<<"2 4 6 8"<<endl;
        else
        {
            long long i;
            for(i=1;; i+=2)
            {
                if(n<=i*i)
                    break;
            }
            long long a,b,c,d,X[5];
            a=(i-2)*(i-2)+1;
            b=(i-2)*(i-2)+i-1;
            c=b+i-1;
            d=c+i-1;
            long long s=i/2;
            X[0]=n-1,X[1]=n+1;
            if(n==a)
            {
                X[2]=i*i;
                X[3]=1+s*8+n;
            }
            else if(n<b)
            {
                X[2]=1+s*8+n;
                X[3]=n-1-(s-1)*8;
            }
            else if(n==b)
            {
                X[2]=1+s*8+n;
                X[3]=3+s*8+n;
            }
            else if(n<c)
            {
                X[2]=3+s*8+n;
                X[3]=n-3-(s-1)*8;
            }
            else if(n==c)
            {
                X[2]=3+s*8+n;
                X[3]=5+s*8+n;
            }
            else if(n<d)
            {
                X[2]=5+s*8+n;
                X[3]=n-(s-1)*8-5;
            }
            else if(n==d)
            {
                X[2]=7+s*8+n;
                X[3]=5+s*8+n;
            }
            else
            {
                X[2]=7+s*8+n;
                X[3]=n-7-(s-1)*8;
            }
            sort(X,X+4);
            for(int i=0; i<3; i++)
                cout<<X[i]<<' ';
            cout<<X[3]<<endl;
        }
    }
    return 0;
}
