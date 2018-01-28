#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,S,p,m;
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("4.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>N>>S>>p;
        m=0;
        int t,r;
        for(int j=0; j<N; j++)
        {
            cin>>t;
            if(t&&(t-1)%3==0)r=t/3+1;
            else
            {
                r=0;
                if(t%3)r=1;
                r+=t/3;
            }
            if(r>=p)m++;
            else if(S)
            {
                if((t+1)%3==0)r=(t+1)/3+1;
                else if(t)r=t/3+1;
                if(r>=p)
                {
                    m++;
                    S--;
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<m<<endl;
    }
    return 0;
}
