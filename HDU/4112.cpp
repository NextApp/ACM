#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long dfs(long long n, long long m, long long k)
{
    int num[3]; num[0] = n, num[1] = m, num[2] = k;
    sort(num, num + 3);
    n = num[2], m = num[1], k = num[0];
    if(n == 1) return 0;
    if(n & 1)return dfs(n / 2 + 1, m, k) + 1;
    else return dfs(n / 2, m, k) + 1;
}
int main()
{
    long long n, m, k;
    int t;
    cin >> t;
    int id = 0;
    while(t--)
    {
        cin>>n>>m>>k;
        long long sum=0;
        cout<<"Case #"<<++id<<": "<<n*m*k-1<<' '<< dfs(n, m, k) <<endl;
    }
    return 0;
}
