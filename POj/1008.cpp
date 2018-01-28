#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char S[23][10]= {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
char M[23][10]= {"pop", "no", "zip", "zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        int a,b,day;
        char c,s[10];
        printf("%d\n",n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%c%s%d",&a,&c,s,&b);
            int month=0;
            for(int j=0; j<19; j++)
                if(!strcmp(M[j],s))
                {
                    month=j;
                    break;
                }
            day=a+month*20+b*365;
            int years=day/260;
            day%=260;
            int tday=day%13+1;
            int mday=day%20;
            printf("%d %s %d\n",tday,S[mday],years);
        }
    }
    return 0;
}
