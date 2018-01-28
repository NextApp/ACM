#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
char M[20][1100][20];
int  M_num[100];
char word[120][100];
int word_len[80],ok;
char vis[200];
int n,num;
int S_OK;
int V[1200][80],O[200];
void dfs(int cur)
{
    if(ok)return ;
    if(cur==num)
    {
        ok=1;
        return ;
    }
    int len=word_len[cur];
    for(int i=0; i<M_num[len]; i++)
        if(!V[i][len])
        {
            int okk=1,lum=0,C[200],C2[200];
            for(int j=0; j<len&&okk; j++)
            {
                char c=M[len][i][j],d=word[cur][j];
                if(!vis[d]&&!O[c])
                {
                    vis[d]=c;
                    O[c]=1;
                    C2[lum]=c;
                    C[lum++]=d;
                }
                else if(vis[d]!=c)okk=0;
            }
            if(okk)
            {
                V[i][len]=1;
                dfs(cur+1);
                V[i][len]=0;
            }
            if(ok)return;
            for(int j=0; j<lum; j++)
                O[C2[j]]=vis[C[j]]=0;
        }
}
char a[100];
char S_word[100][80];
int main()
{
   // freopen("1.txt","r",stdin);
    scanf("%d",&n);
    char w[20];
    memset(M_num,0,sizeof(M_num));
    for(int i=0; i<n; i++)
    {
        scanf("%s",&w);
        int len=strlen(w);
        strcpy(M[len][M_num[len]++],w);
    }
    getchar();
    while(gets(a)!=NULL)
    {
        stringstream fin(a);
        num=0;
        S_OK=0;
        int S_num=0;
        while(fin>>word[num])
        {
            word_len[num]=strlen(word[num]);
            if(!M_num[word_len[num]])S_OK=1;
            int o=1;
            for(int i=0; i<num&&o; i++)
                if(!strcmp(word[i],word[num]))
                    o=0;
            strcpy(S_word[S_num++],word[num]);
            if(o)num++;
        }
        memset(vis,0,sizeof(vis));
        memset(V,0,sizeof(V));
        memset(O,0,sizeof(O));
        ok=0;
        if(!S_OK)dfs(0);
        if(ok)
        {
            for(int i=0; i<S_num; i++)
            {
                for(int j=0; S_word[i][j]; j++)
                    printf("%c",vis[S_word[i][j]]);
                if(i<S_num-1)printf(" ");
            }
        }
        else
        {
            for(int i=0; i<S_num; i++)
            {
                for(int j=0; j<S_word[i][j]; j++)
                    printf("*");
                if(i<S_num-1)printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
