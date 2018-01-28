#include<cstdio>
#include<cstring>
#define N 32000
int M[6500000],n,q[108],m,ok;
char S[108];
int ddd(int i,int result)
{
    M[(result+N)*100+i]=1;
    if(ok)return 0;
    if(i==n)
    {
        if(result==m)
        {
            printf("%d",q[0]);
            for(int i=1; i<n; i++)
            printf("%c%d",S[i],q[i]);
            printf("=%d\n",m);
            ok=1;
            return 0;
        }
        return 0;
    }
    else if(!ok)
    {
        if(result*q[i]<=N&&result*q[i]>=-N)
        {
            if(!M[(result*q[i]+N)*100+i])
            {
                S[i]='*';
                ddd(i+1,result*q[i]);
            }
        }
        if(!(result%q[i]))
        {
            if(!M[(result/q[i]+N)*100+i])
            {
                S[i]='/';
                ddd(i+1,result/q[i]);
            }
        }
        if(result+q[i]<=N)
        {
            if(!M[(result+q[i]+N)*100+i])
            {
                S[i]='+';
                ddd(i+1,result+q[i]);
            }
        }
        if(result-q[i]>=-N)
        {
            if(!M[(result-q[i]+N)*100+i])
            {
                S[i]='-';
                ddd(i+1,result-q[i]);
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int num;
    scanf("%d",&num);
    while(num--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&q[i]);
        scanf("%d",&m);
        ok=0;
        memset(M,0,sizeof(M));
        memset(S,0,sizeof(S));
        ddd(1,q[0]);
        if(!ok)
        {
            printf("NO EXPRESSION\n");
        }
    }
    return 0;
}
