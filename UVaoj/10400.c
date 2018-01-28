#include<cstdio>
#include<cstring>
#define N 32000
#define E 6400000
int q[E],m,s[108],ok,n,M[E],D[E];
char F[E],S[108];
int bfs()
{
    int rear=0,front=0;
    q[rear++]=(s[0]+N)*100;
    while(front<rear)
    {
        int u=q[front++];
        int a=u/100-N,i=u%100+1,l;
        if(i<n)
        {
            if(a*s[i]<N&&a*s[i]>-N)
            {
                l=(a*s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='*';
                    q[rear++]=l;
                }
            }
            if(!(a%s[i]))
            {
                l=(a/s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='/';
                    q[rear++]=l;
                }
            }
            if(a+s[i]<N)
            {
                l=(a+s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='+';
                    q[rear++]=l;
                }
            }
            if(a-s[i]>-N)
            {
                l=(a-s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='-';
                    q[rear++]=l;
                }
            }
        }
        else
        {
            if(a==m)
            {

                int o=1,c=D[u];
                S[0]=F[u];
                while(o<n-1)
                {
                    S[o++]=F[c];
                    c=D[c];
                }
                printf("%d",s[0]);
                for(int i=1; i<n; i++)
                    printf("%c%d",S[n-i-1],s[i]);
                printf("=%d\n",m);
                ok=1;
                return 0;
            }
        }
    }
}
int main()
{
    // freopen("1.txt","r",stdin);
    int num;
    scanf("%d",&num);
    while(num--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&s[i]);
        scanf("%d",&m);
        ok=0;
        memset(M,0,sizeof(M));
        bfs();
        if(!ok)
        {
            printf("NO EXPRESSION\n");
        }
    }
    return 0;
}
