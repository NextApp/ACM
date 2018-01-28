#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define N 12000
using namespace std;
double a,b,c;
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>a>>b>>c)
    {
     if(c*2>a||c*2>b)cout<<"Second"<<endl;
     else cout<<"First"<<endl;
    }
    return 0;
}
