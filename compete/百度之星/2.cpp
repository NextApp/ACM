#include<iostream>
#include<cstring>
#define N 1000000
using namespace std;
char M[N];
int s[100500];
int main()
{
    int n,k,a[15],b[15];
    cin>>n>>k;
    memset(M,0,sizeof(M));
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        for(int t=1; a[i]+b[i]*t<N; t++)
            M[a[i]+b[i]*t]=1;
    }
    int o=0;
    for(int i=0;i<N&&o<50001;i++)
    if(M[i])s[o++]=i;
    for(int i=0;i<o-1;i++)
    M[s[i]+s[i+1]]=1;
    o=0;
    for(int s=0;;s++)
    {
        if(M[s])o++;
        if(o==k-1)
        {
            cout<<s<<endl;
            break;
        }
    }
    return 0;
}
