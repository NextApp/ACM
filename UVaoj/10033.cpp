#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000
using namespace std;
int M[1200];
int main()
{
  //  freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    getchar();
    getchar();
    int id=0;
    while(T--)
    {
        if(id)printf("\n");
        id=1;
        char a[10];
        int num=0;
        memset(M,0,sizeof(M));
        while(gets(a)!=NULL)
        {
            if(a[0]=='\0')break;
            M[num++]=(a[0]-'0')*100+(a[1]-'0')*10+a[2]-'0';
        }
        int order=0;
        int vis[20],i=0;
        memset(vis,0,sizeof(vis));
        while(1)
        {
            order++;
            int cmd=M[i];
            i++;
            int ok=0,a=cmd/100+'0',b=(cmd/10)%10,c=cmd%10;
            switch (a)
            {
            case '1':
                if(!b&&!c)ok=1;
                break;
            case '2':
                vis[b]=c;
                break;
            case '3':
                vis[b]=(vis[b]+c)%N;
                break;
            case '4':
                vis[b]=(vis[b]*c)%N;
                break;
            case '5':
                vis[b]=vis[c];
                break;
            case '6':
                vis[b]=(vis[b]+vis[c])%N;
                break;
            case '7':
                vis[b]=(vis[b]*vis[c])%N;
                break;
            case '8':
                vis[b]=M[vis[c]];
                break;
            case '9':
                M[vis[c]]=vis[b];
                break;
            default:
                if(vis[c]!=0)i=vis[b];
                break;
            }
            if(ok)break;
            if(i>=1000)break;
        }
        printf("%d\n",order);
    }
    return 0;
}
