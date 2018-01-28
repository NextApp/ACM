#include<stdio.h>
#include<string.h>
#define MAXD 20010
#define MAXM 100010
#define INF 1000000000
int N, M, S, T, q[MAXD], inq[MAXD];
int first[MAXD], next[MAXM], v[MAXM], w[MAXM], d[MAXD], e;
void add(int a, int b, int c)
{
    w[e] = c;
    v[e] = b;
    next[e] = first[a];
    first[a] = e;
    e ++;
}
void init()
{
    int i, j, a, b, c;
    scanf("%d%d%d%d", &N, &M, &S, &T);
    memset(first, -1, sizeof(first));
    e = 0;
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
}
void SPFA()
{
    int i, j, front ,rear, u;
    front = rear = 0;
    for(i = 0; i < N; i ++)        d[i] = INF;
    d[S] = 0;
    q[rear ++] = S;
    while(front != rear)
    {
        u = q[front ++];
        if(front > N)            front = 0;
        inq[u] = 0;
        for(i = first[u]; i != -1; i = next[i])            if(d[u] + w[i] < d[v[i]])
            {
                d[v[i]] = d[u] + w[i];
                if(!inq[v[i]])
                {
                    q[rear ++] = v[i];
                    if(rear > N)                        rear = 0;
                    inq[v[i]] = 1;
                }
            }
    }
    if(d[T] == INF)        printf("unreachable\n");
    else        printf("%d\n", d[T]);
}
int main()
{
    int t, tt;
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        init();
        printf("Case #%d: ", tt + 1);
        SPFA();
    }
    return 0;
}
