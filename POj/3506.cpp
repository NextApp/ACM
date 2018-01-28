#include<stdio.h>
#include<string.h>
char a[1001000],b[1001000];
int main()
{
    int id=1;
    while(scanf("%s",a+1))
    {
        if(a[1]=='0')break;
        else
        {
            a[0]='1';
            int s='0';
            int len=strlen(a);
            for(int i=len-1; i>=1; i--)
            {
                if(a[i]>=s)
                    s=a[i]-s+'0';
                else
                {
                    a[i-1]-=1;
                    s=a[i]-s+10+'0';
                }
                b[i-1]=s;
            }
            b[len-1]='\0';
            printf("%d. ",id++);
            if(b[0]=='0')printf("IMPOSSIBLE\n");
            else
                printf("%s\n",b);
        }
    }
    return 0;
}
