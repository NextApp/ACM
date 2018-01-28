#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x[100200],y[100200],z[100200];
int main()
{
   // freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for(int i=0; i<Q; i++)
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
        int s=0;
        for(int i=1; i<=n; i++)
        {
            int k=1;
            for(int j=Q-1; j>=0; j--)
                if(x[j]<=i&&i<=y[j])
                {
                    k=z[j];
                    break;
                }
            s+=k;
        }
        printf("Case %d: The total value of the hook is %d.\n",id++,s);

    }
    return 0;
}
