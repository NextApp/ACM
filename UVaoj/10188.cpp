#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char a[120][12000],b[120][12000],numa[120000],numb[120000];
int main()
{
   // freopen("1.txt","r",stdin);
    int id=1;
    while(scanf("%d",&n)&&n)
    {
        getchar();
        int lena=0,lenb=0;
        for(int i=0; i<n; i++)
        {
            gets(a[i]);
            for(int j=0; a[i][j]; j++)
                if(a[i][j]<='9'&&a[i][j]>='0')
                {
                    numa[lena++]=a[i][j];
                }
        }
            numa[lena]='\0';
        scanf("%d",&m);
        getchar();
        for(int i=0; i<m; i++)
        {
            gets(b[i]);
            for(int j=0; b[i][j]; j++)
                if(b[i][j]<='9'&&b[i][j]>='0')
                {
                    numb[lenb++]=b[i][j];
                }
        }
            numb[lenb]='\0';
        int answer=0;
        if(n==m)
        {
            int ok=1;
            for(int i=0;i<n&&ok;i++)
            if(strcmp(a[i],b[i]))
            ok=0;
            if(ok)answer=1;
            else
            {
                if(!strcmp(numa,numb))answer=2;
            }
        }
        else if(!strcmp(numa,numb))answer=2;
        printf("Run #%d: ",id++);
        if(answer==1)printf("Accepted\n");
        else if(answer==2)printf("Presentation Error\n");
        else printf("Wrong Answer\n");
    }
    return 0;
}
