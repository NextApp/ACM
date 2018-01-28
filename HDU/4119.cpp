#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<sstream>
#define N 60
using namespace std;
int n,m,OK=0,num;
char code[N][N],mask[N][N];
char words[120][30];
int lena[120];
char result[120][30],M[10][10000];
char SS[1000][100];
void xuanzuan(char a[N][N])
{
    char b[N][N];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            b[j][n-i-1]=a[i][j];
    memcpy(a,b,sizeof(b));
}
char a[3000],b[3000],c[3000],d[3000];
void deal(char a[])
{
    int k=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(mask[i][j]=='*')
            {
                if(code[i][j]!='.')a[k++]=code[i][j];
                else a[k++]=' ';
            }
    a[k]='\0';
}
void xuan()
{
    deal(a);
    xuanzuan(mask);
    deal(b);
    xuanzuan(mask);
    deal(c);
    xuanzuan(mask);
    deal(d);
}
int compare(char M[],char a[],int len)
{
    for(int i=0; i<len; i++)
        if(M[i]!=a[i])return 0;
    return 1;
}
int chuli(int n)
{
    num=0;
    for(int i=0; i<n; i++)
    {
        int ok=0;
        for(int j=0; j<m; j++)
            if(!strcmp(words[j],SS[i]))
            {
                strcpy(result[num++],words[j]);
                ok=1;
                break;
            }
        if(!ok)return -1;
    }
    if(num>0)OK=1;
    return 1;
}
int cmp(const void *_a,const void *_b)
{
    char *a=(char*)_a;
    char *b=(char*)_b;
    return strcmp(a,b);
}
char tt[12000];
void pingjie()
{
    xuan();
    strcpy(M[0],a);
    strcat(M[0],b);
    strcat(M[0],c);
    strcat(M[0],d);
    strcpy(M[1],b);
    strcat(M[1],c);
    strcat(M[1],d);
    strcat(M[1],a);
    strcpy(M[2],c);
    strcat(M[2],d);
    strcat(M[2],a);
    strcat(M[2],b);
    strcpy(M[3],d);
    strcat(M[3],a);
    strcat(M[3],b);
    strcat(M[3],c);
    char cc[100];
    for(int i=0; i<4&&!OK; i++)
    {
        int ok=0;
        stringstream fin(M[i]);
        while(fin>>cc)
        {
            if(!ok)strcpy(tt,cc);
            else
            {
                strcat(tt," ");
                strcat(tt,cc);
            }
            ok=1;
        }
        strcpy(M[i],tt);
    }
    qsort(M,4,sizeof(M[0]),cmp);
    for(int i=0; i<4&&!OK; i++)
    {
        int k=0;
        stringstream fin(M[i]);
        while(fin>>SS[k])k++;
        chuli(k);
    }
}
int main()
{
    int T,id=1;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        OK=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%s",code[i]);
        for(int j=0; j<n; j++)
            scanf("%s",mask[j]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%s",words[i]);
        qsort(words,m,sizeof(words[0]),cmp);
        for(int i=0; i<m; i++)
            lena[i]=strlen(words[i]);
        pingjie();
        printf("Case #%d: ",id++);
        if(OK)
        {
            for(int i=0; i<num-1; i++)
                printf("%s ",result[i]);
            printf("%s\n",result[num-1]);
        }
        else printf("FAIL TO DECRYPT\n");
    }
    return 0;
}
