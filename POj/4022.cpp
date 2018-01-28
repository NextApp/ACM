#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
char a[120][120];
int main()
{
 // freopen("in.in","r",stdin);
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0; i<n; i++)
            scanf("%s",a[i]);
        double sum=0;
        for(int i=0; i<n; i++)
        {
            int t=0;
            for(int j=0; j<m; j++)
                if(a[i][j]=='.')
                {
                    if(t%2)sum+=1;
                }
                else t++,sum+=0.5;
        }
        cout<<sum<<endl;
    }
    return 0;
}
