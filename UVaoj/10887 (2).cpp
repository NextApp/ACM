#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char M[2500000][22];
int cmp(const void *_a,const void*_b)
{
    char *a=(char*)_a;
    char *b=(char*)_b;
    return strcmp(a,b);
}
char S[1600][12],N[1600][12];
int main()
{
   // freopen("1.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int m,n,o=0;
        cin>>m>>n;
        getchar();
        for(int j=0; j<m; j++)
            gets(S[j]);
        for(int k=0; k<n; k++)
        {
            gets(N[k]);
            for(int j=0; j<m; j++)
            {
                int l=strlen(S[j]);
                strcpy(M[o],S[j]);
                strcpy(M[o++]+l,N[k]);
            }
        }
        int ok=0;
        qsort(M,o,sizeof(M[0]),cmp);
        for(int j=0;j<o-1;j++)
        {
            while(!strcmp(M[j],M[j+1]))j++;
            ok++;
        }
        if(o)ok++;
        cout<<"Case "<<i+1<<": "<<ok<<endl;
    }
    return 0;
}
