#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[10020000];
int main()
{
  //  freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        cin>>s;
        int len=strlen(s),out=0,put=0,in=0,ok=1;
        for(int j=0; j<len; j++)
        {
            if(s[j]=='o')
            {
                if(j+2<len&&s[j+1]=='n'&&s[j+2]=='e')
                {
                    j+=2;
                    in=out=0;
                }
                else if(j+2<len&&s[j+1]=='u'&&s[j+2]=='t')j+=2,out++;
                else
                {
                    ok=0;
                    break;
                }
                in=0;
            }
            else if(s[j]=='i')
            {
                if(j+1<len&&s[j+1]=='n')j+=1,in++;
                else
                {
                    ok=0;
                    break;
                }
                out=0;
            }
            else if(s[j]=='p')
            {
                if(j+2<len&&s[j+1]=='u'&&s[j+2]=='t')
                {
                    if(j+4<len&&s[j+3]=='o'&&s[j+4]=='n')
                    {
                        if(j+5<len&&s[j+5]=='e')
                        {
                            if(!out&&!in)
                            {
                                ok=0;
                                break;
                            }
                            else
                            {
                                j+=5;
                                continue;
                            }
                        }
                        j+=4;
                    }
                    else if(!out&&!in)
                    {
                        ok=0;
                        break;
                    }
                    else j+=2;
                }
                else
                {
                    ok=0;
                    break;
                }
                in=out=0;
            }
            else
            {
                ok=0;
                break;
            }
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
