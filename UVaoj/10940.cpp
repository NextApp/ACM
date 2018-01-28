#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        /*queue<int>Q;
        for(int i=1;i<=n;i++)
        Q.push(i);
        int t=0;
        while(!Q.empty())
        {
            t++;
            if(t==n)
            {
                int s=Q.front();
                cout<<s<<' ';
                break;
             }
            Q.pop();
            int m=Q.front();
            Q.push(m);
            Q.pop();
        }*/
        int sum=0;
        for(int j=0;j<=n-1;j++)
        {
            sum+=pow(2,j);
            if(sum>=n-1)
            {
                sum-=pow(2,j);
                break;
            }
        }
        if(n!=1)cout<<(n-1-sum)*2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
