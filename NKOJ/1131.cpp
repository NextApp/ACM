#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 1000020
using namespace std;
int d[2015][2015];
char a[2015],b[2015];
int main()
{
  // freopen("1.txt","r",stdin);
    while(~scanf("%s%s",a,b))
    {
        int lena=strlen(a);
        int lenb=strlen(b);
        int temp;
        for(int i=1; i<=lena; i++)
            for(int j=1; j<=lenb; j++)
            {
                if(i==0||j==0)
                {
                    d[i][j]=max(i,j);
                    continue;
                }
                if(a[i-1]==b[j-1])d[i][j]=d[i-1][j-1];
                else
                {
                    temp=min(d[i-1][j]+1,d[i][j-1]+1);
                    d[i][j]=min(temp,d[i-1][j-1]+1);
                }
            }
        printf("%d\n",d[lena][lenb]);
    }
    return 0;
}
