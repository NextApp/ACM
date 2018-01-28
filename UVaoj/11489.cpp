#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1220];
int m[12];
int main()
{
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",a);
        memset(m,0,sizeof(m));
        int len=strlen(a),sum=0;
        for(int i=0; i<len; i++)
        {
            m[(a[i]-'0')%3]++;
            sum+=a[i]-'0';
        }
        printf("Case %d: ",id++);
        if(sum%3==0)
        {
            if(m[0]%2==0)printf("T");
            else printf("S");
        }
        else
        {
            if(m[sum%3]>0)
            {
                if(m[0]%2==0)printf("S");
                else printf("T");
            }
            else printf("T");
        }
        printf("\n");
    }
    return 0;
}
