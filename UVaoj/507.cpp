#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
   // freopen("2.txt","r",stdin);
    int num,n;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        int a,X1=-1,X2=-2,x1,ok=0,sum=0,max=0;
        for(int j=1; j<n; j++)
        {
            cin>>a;
            if(!ok&&a>0)
            {
                sum=a;
                ok=1;
                x1=j;
                if(sum>max){max=sum;X1=X2=x1;}
            }
            else if(ok)
            {
                if(sum+a>=0)
                {
                    sum+=a;
                    if(sum>max||(sum==max&&X2-X1<j-x1))
                    {
                        max=sum;
                        X2=j;
                        X1=x1;
                    }
                }
                else
                  ok=0;
            }
        }
        if(max>0)cout<<"The nicest part of route "<<i+1<<" is between stops "<<X1<<" and "<<X2+1<<endl;
        else cout<<"Route "<<i+1<<" has no nice parts"<<endl;
    }
    return 0;
}
