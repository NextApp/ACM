#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
void change(int a[],int b[])
{
    int c[60];
    for(int i=0; i<52; i++)
        c[i]=a[b[i]];
    memcpy(a,c,sizeof(c));
}
char S[10][20]= {"Clubs","Diamonds","Hearts","Spades"};
void print(int c)
{
    int C=c/13;
    if(c%13==0)
    {
        C--;
        c=13;
    }
    else c=c%13;
    if(c==1)printf("Ace");
    else if(c==11)printf("Jack");
    else if(c==12)printf("Queen");
    else if(c==13)printf("King");
    else printf("%d",c);
    printf(" of %s\n",S[C]);

}
int M[120][60];
int main()
{
   // freopen("1.txt","r",stdin);
    int T,n,id=0;
    scanf("%d",&T);
    while(T--)
    {
        if(id)printf("\n");
        id=1;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<52; j++)
            {
                scanf("%d",&M[i][j]);
                M[i][j]--;
            }
        int R[60];
        for(int t=0; t<4; t++)
            for(int i=0; i<13; i++)
                R[i+13*t]=(i+1)%13+13*t;
        char a[100];
        gets(a);
        while(gets(a)!=NULL)
        {
            if(a[0]=='\0')break;
            else
            {
                stringstream fin(a);
                int m;
                fin>>m;
                m--;
                change(R,M[m]);
            }
        }
        for(int i=0; i<52; i++)
            print(R[i]+1);
    }
    return 0;
}
