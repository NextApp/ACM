#include<iostream>
#include<cstdio>
#include<cstring>
#define N 120
using namespace std;
char input[N][N],example[]="the quick brown fox jumps over the lazy dog";
char vis[200],evis[200];
int lena,num;
void print(int ok)
{
    if(ok)
    {
        for(int i=0;i<num;i++)
        {for(int j=0;input[i][j];j++)
        if(input[i][j]!=' ')printf("%c",evis[input[i][j]]);
        else printf(" ");
        printf("\n");
    }
        return ;
    }
    printf("No solution.\n");
}
int judge(int t)
{
    memset(vis,0,sizeof(vis));
    memset(evis,0,sizeof(evis));
    for(int i=0;i<lena;i++)
    {
        char c=input[t][i],d=example[i];
        if(c==' ')continue;
        if(!vis[d])
        {
            if(!evis[c])vis[d]=c,evis[c]=d;
            else return 0;
        }
        else if(c!=vis[d])return 0;
    }
    return 1;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int numcase,id=0;
    num=0;
    lena=strlen(example);
    scanf("%d",&numcase);
    char A[100];
    getchar();getchar();
    while(gets(A)!=NULL)
    {
        if(id)printf("\n");
        id=1;
        num=1;
        strcpy(input[0],A);
        while(gets(input[num])!=NULL)
        {
            if(input[num][0]=='\0')break;
            num++;
        }
        int OK=0;
        for(int t=0;t<num&&!OK;t++)
        {
            int ok=1;
            if(strlen(input[t])!=lena)ok=0;
            for(int i=0;i<lena&&ok;i++)
            if(input[t][i]==' '&&example[i]!=' ')ok=0;
            else if(example[i]==' '&&input[t][i]!=' ')ok=0;
            if(ok)OK=judge(t);
        }
        print(OK);
    }
    return 0;
}
