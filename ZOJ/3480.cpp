#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char scan[100];
int classnum;
struct T
{
    int oksuper;
    char classname[30];
    int methodnum;
    char super[30];
    char method[220][30];
    int vis[220];
} Class[3200];
char first[30],second[30],third[30];
int init()
{
    int i,k=0,ok=0;
    for(i=0; scan[i]!=' '&&scan[i]; i++)
        first[k++]=scan[i];
    first[k]=0;
    i++;
    k=0;
    for(; scan[i]; i++)
    {
        if(scan[i]==':')
        {
            ok=1;
            break;
        }
        else if(scan[i]=='.')
        {
            ok=-1;
            break;
        }
        else
        {
            second[k++]=scan[i];
        }
    }
    second[k]=0;
    k=0;
    if(ok)
    {
        i++;
        for(; scan[i]; i++)
            third[k++]=scan[i];
    }
    third[k]=0;
    return ok;
}
void NO()
{
    printf("oops!\n");
}
int OKnum;
void dfs(int cur)
{
    for(int i=0; i<Class[cur].methodnum; i++)
    {
        if(Class[cur].vis[i]&&!strcmp(Class[cur].method[i],third))
        {
            OKnum=1;
            printf("invoke %s.%s\n",Class[cur].classname,third);
        }
    }
    if(OKnum)return;
    if(Class[cur].oksuper)
    {
        for(int i=0; i<classnum; i++)
        {
            if(!strcmp(Class[i].classname,Class[cur].super))
            {
                dfs(i);
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int casenum;
    scanf("%d",&casenum);
    while(casenum--)
    {
        memset(Class,0,sizeof(Class));
        while(gets(scan)!=NULL)
        {
            if(!strcmp("begin",scan))
                break;
        }
        classnum=0;
        while(gets(scan)!=NULL)
        {
            if(!strcmp(scan,"end"))break;
            else
            {
                int ok=init();
                if(first[1]=='l')
                {
                    if(!ok)
                    {
                        int have=0;
                        for(int i=0; i<classnum; i++)
                        {
                            if(!strcmp(Class[i].classname,second))
                            {
                                have=1;
                                break;
                            }
                        }
                        if(have)NO();
                        else
                        {
                            strcpy(Class[classnum++].classname,second);
                            printf("%s\n",scan);
                        }
                    }
                    else
                    {
                        int OK=0,okk=0,J;
                        for(int i=0; i<classnum&&!OK; i++)
                        {
                            if(!strcmp(second,Class[i].classname))
                            {
                                OK=1;
                            }
                            if(!strcmp(third,Class[i].classname))
                            {
                                okk=1;
                                J=i;
                            }
                        }
                        if(OK||!okk)NO();
                        else
                        {
                            Class[classnum].oksuper=1;
                            strcpy(Class[classnum].classname,second);
                            strcpy(Class[classnum++].super,third);
                            printf("%s\n",scan);
                        }
                    }
                }
                else if(first[1]=='e')
                {
                    int OK=-1;
                    for(int i=0; i<classnum; i++)
                        if(!strcmp(second,Class[i].classname))OK=i;
                    if(OK==-1)
                    {
                        NO();
                        continue;
                    }
                    int def=1;
                    for(int i=0; i<Class[OK].methodnum&&def; i++)
                    {
                        if(Class[OK].vis[i]&&!strcmp(third,Class[OK].method[i]))
                        {
                            def=0;
                        }
                    }
                    if(!def)
                    {
                        printf("re%s\n",scan);
                    }
                    else
                    {
                        Class[OK].vis[Class[OK].methodnum]=1;
                        strcpy(Class[OK].method[Class[OK].methodnum++],third);
                        printf("%s\n",scan);
                    }
                }
                else if(first[1]=='n')
                {
                    int classok=-1,meok=-1;
                    for(int i=0; i<classnum; i++)
                    {
                        if(!strcmp(second,Class[i].classname))
                        {
                            classok=i;
                            break;
                        }
                    }
                    if(classok!=-1)
                    {
                        for(int i=0; i<Class[classok].methodnum; i++)
                        {
                            if(Class[classok].vis[i]&&!strcmp(third,Class[classok].method[i]))
                            {
                                meok=i;
                                break;
                            }
                        }
                        if(meok!=-1)
                        {
                            Class[classok].vis[meok]=0;
                            printf("%s\n",scan);
                        }
                        else NO();
                    }
                    else NO();

                }
                else if(first[1]=='a')
                {
                    OKnum=0;
                    for(int i=0; i<classnum; i++)
                    {
                        if(!strcmp(second,Class[i].classname))
                        {
                            dfs(i);
                        }
                    }
                    if(!OKnum)NO();
                }
            }
        }
        printf("\n");
    }
    return 0;
}
