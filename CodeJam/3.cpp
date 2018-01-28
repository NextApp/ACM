#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int vis[2000200];
int main()
{
    int n;
    freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int A,B;
        cin>>A>>B;
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int j=A; j<=B; j++)
        {
            int s=(int)log10(j)+1;
            for(int k=1; k<s; k++)
            {
                int t=pow(10,k);
                int a=(j%t)*pow(10,s-k)+j/t;
                if(a>j&&a<=B)
                {
                    sum++;
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<sum<<endl;
    }
    return 0;
}
