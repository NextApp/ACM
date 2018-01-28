#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct T
{
    char a[13],b[13];
} M[100100];
int OK=1,k=0;
char S[30];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return strcmp(a->b,b->b);
}
int binary(char a[])
{
    int s=-1,e=k;
    while(s<=e)
    {
        int o=(s+e)/2;
        int d=strcmp(a,M[o].b);
        if(!d)
        {
            strcpy(S,M[o].a);
            return 1;
        }
        else if(d<0)e=o-1;
        else s=o+1;
    }
    return 0;
}
int main()
{
  //  freopen("1.txt","r",stdin);
    char s[30];
    while(gets(s)!=NULL)
    {
        if(s[0]=='\0')
        {
            qsort(M,k,sizeof(M[0]),cmp);
            OK=0;
            continue;
        }
        if(OK)
        {
            int j=0;
            for(int i=0; s[i]; i++)
                if(s[i]==' ')
                {
                    j=i;
                    break;
                }
            s[j]='\0';
            strcpy(M[k].a,s);
            strcpy(M[k++].b,s+j+1);
        }
        else
        {
            if(binary(s))cout<<S<<endl;
            else cout<<"eh"<<endl;
        }
    }
    return 0;
}
