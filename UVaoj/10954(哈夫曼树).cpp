#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q[100][5021];
int main()
{
    int n;
    //freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            for(int i=0; i<n; i++)
                cin>>q[0][i];
            sort(q[0],q[0]+n);
            int sum,k=1,f=0,l=0,i=0;
            sum=q[k][f]=q[k-1][i]+q[k-1][i+1];
            i=2;
            while(1)
            {
                if(i<n)
                {
                    int m1,m2;
                    if(q[k][f]>q[k-1][i])
                    {
                        m1=q[k-1][i++];
                        if(i<n&&q[k][f]>q[k-1][i])m2=q[k-1][i++];
                        else m2=q[k][f++];
                    }
                    else
                    {
                        m1=q[k][f++];
                        if(f<=l&&q[k][f]<q[k-1][i])m2=q[k][f++];
                        else m2=q[k-1][i++];
                    }
                    q[k][++l]=m1+m2;
                    sum+=q[k][l];
                }
                else
                {
                    k++;
                    i=f;
                    n=l+1;
                    if(i+1<n)
                    {
                        q[k][f=0]=q[k-1][i]+q[k-1][i+1];
                        sum+=q[k][f];
                        i+=2;
                    }
                    else break;
                    l=0;
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
