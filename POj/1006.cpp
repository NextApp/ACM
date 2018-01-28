#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int p,e,i,d,m[30000];
int main()
{
    int id=1;
    while(~scanf("%d%d%d%d",&p,&e,&i,&d))
    {
        if(p==-1&&e==-1&&i==-1&&d==-1)break;
        for(int k=1; k<=21252; k++)
            if((k-p)%23==0&&(k-e)%28==0&&(k-i)%33==0)
            {
                int s=((k-d)%21252+21252)%21252;
                s=s?s:21252;
                printf("Case %d: the next triple peak occurs in %d days.\n",id++,s);
                break;
            }
    }
    return 0;
}
