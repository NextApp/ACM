#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#define INF 100000000
using namespace std;
int numcase,n,d[105][205],a[105],b[105];
char A[410];
int main()
{
  //  freopen("1.txt","r",stdin);
    scanf("%d",&numcase);
    getchar();
    getchar();
    int id=0;
    while(numcase--)
    {
        if(id)printf("\n");
        id=1;
        n=1;
        int S;
        scanf("%d",&S);
        getchar();
        while(gets(A)!=NULL)
        {
            if(A[0]=='\0')break;
            else
            {
                stringstream fin(A);
                fin>>a[n]>>b[n];
                if(a[n]<=S)
                n++;
            }
        }
        a[n]=S;
        for(int i=0; i<=n; i++)
            for(int j=0; j<=200; j++)
                d[i][j]=INF;
        for(int i=0; i<=100; i++)
            d[0][i]=0;
        a[0]=0;
        b[0]=0;
        if(S>=a[1])
        {
            for(int i=0; i<n; i++)
            {
                int t=a[i+1]-a[i];
                for(int j=0; j<=200; j++)
                    if(d[i][j]!=INF)
                    {
                        for(int k=j>=t?0:t-j; k+j<=200; k++)
                        {
                        if(!i)
                        {
                            if(j-t>=0)d[i+1][j-t]=d[i][j];
                            break;
                        }
                        else d[i+1][j+k-t]=min(d[i+1][j+k-t],d[i][j]+k*b[i]);
                        }
                    }
            }
        }
        if(d[n][100]!=INF)printf("%d\n",d[n][100]);
        else printf("Impossible\n");
    }
    return 0;
}
