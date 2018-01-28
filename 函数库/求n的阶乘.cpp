#include<iostream>
#include<cstring>
using namespace std;
const int maxn=3000;
int f[maxn];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
    memset(f,0,sizeof(f));
    f[0]=1;
    for(i=2;i<=n;i++)
    {
        int c=0;
        for(j=0;j<maxn;j++)
        {
            int s=f[j]*i+c;
            f[j]=s%10;
            c=s/10;
        }
    }
    cout<<n<<'!'<<endl;
    for(j=maxn-1;j>=0;j--)if(f[j])break;
    for(i=j;i>=0;i--)cout<<f[i];
    cout<<endl;
    }
    return 0;
}
