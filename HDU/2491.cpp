#include<cstring>
#include<cstdio>
#include<cstdlib>
struct T
{
    int a,b,d;
} A[120000];
int cmp(const void *_a,const void*_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return a->d - b->d;
}
int main()
{
    int num;
    while(scanf("%d",&num)==1)
    {
        if(!num)break;
        else
        {
            for(int i=0; i<num; i++)
            {
                scanf("%d%d",&A[i].a,&A[i].b);
                A[i].d=A[i].a+(A[i].b-A[i].a)/2-1;
                if((A[i].b-A[i].a)%2)A[i].d++;
            }
            qsort(A,num,sizeof(T),cmp);
            int ok=1,t=A[0].a;
            for(int i=0; i<num; i++)
            {
                t=t<A[i].a?A[i].a:t;
                if(t>A[i].d)
                {
                    ok=0;
                    break;
                }
                else t=(A[i].b+A[i].a)/2+1;
            }
            if(ok)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
