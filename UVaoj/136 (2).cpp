#include<iostream>
#include<queue>
using namespace std;
#define N 1500
typedef long long ll;
int s[3]= {2,3,5};
priority_queue<ll,vector<ll>,greater<ll> > pq;
int main()
{
    ll t,p=0,n=0;
    pq.push(1);
    while(n<N)
    {
        t=pq.top();
        pq.pop();
        if(p!=t)
        {
            p=t;
            n++;
            for(int i=0; i<3; i++)
            {
                pq.push(t*s[i]);
            }
        }
    }
    cout<<"The 1500'th ugly number is "<<t<<'.'<<endl;
}
