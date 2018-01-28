#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct T
{
    char a[20];
    int p;
} word[400200];
struct Node
{
    int a[400];
    int n;
} A[26000];
int word_len;
char Word[26000][20];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return strcmp(a->a,b->a);
}
int d[25040];
int b_search(char b[],int len)
{
    int s=0,e=len-1;
    while(s<=e)
    {
        int k=(s+e)>>1;
        int ok=strcmp(Word[k],b);
        if(!ok)return k;
        else if(ok>0) e=k-1;
        else s=k+1;
    }
    return -1;
}
int main()
{
    // freopen("1.txt","r",stdin);
    word_len=0;
    while(~scanf("%s",word[word_len].a))
    {
        strcpy(Word[word_len],word[word_len].a);
        word[word_len].p=word_len++;
    }
    int len=word_len;
    memset(A,0,sizeof(A));
    char a[20],b[20];
    for(int i=0; i<len; i++)
    {
        int l=strlen(word[i].a);
        for(int j=0; j<l; j++)
        {
            strcpy(a,word[i].a);
            a[j]=1;
            int t=0;
            for(int k=0; k<l; k++)
                if(j!=k)b[t++]=word[i].a[k];
            b[t]='\0';
            int ok=b_search(b,len);
            if(ok!=-1)
            {
                int w=i;
                if(w<ok)w=ok,ok=i;
                if(w!=ok)A[w].a[A[w].n++]=ok;
            }
            word[word_len].p=i;
            strcpy(word[word_len++].a,a);
        }
    }
    qsort(word,word_len,sizeof(word[0]),cmp);
    int C[3000];
    for(int i=0; i<word_len-1; i++)
    {
        int t=0,ok=0;
        while(i<word_len-1&&!strcmp(word[i].a,word[i+1].a))
        {
            ok=1;
            C[t++]=word[i].p;
            i++;
        }
        if(ok)
        {
            C[t++]=word[i].p;
            sort(C,C+t);
            for(int j=1; j<t; j++)
                for(int k=0; k<j; k++)
                {
                    int m=C[j],n=C[k];
                    if(n!=m&&strcmp(Word[n],Word[m]))
                        A[m].a[A[m].n++]=n;
                }
            i--;
        }
    }
    int mm=0;
    for(int i=0; i<len; i++)
    {
        d[i]=1;
        for(int j=0; j<A[i].n; j++)
        {
            int k=A[i].a[j];
            d[i]=max(d[k]+1,d[i]);
        }
        mm=max(d[i],mm);
    }
    printf("%d\n",mm);
    return 0;
}
