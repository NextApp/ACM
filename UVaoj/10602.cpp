#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct S
{
    int n;
    char M[120];
} A[120];
int MMM(char a[],char b[])
{
    int i=0,num=0;
    while(a[i]&&b[i])
    {
        if(a[i]==b[i])num++;
        else break;
        i++;
    }
    return num;
}
char q[120][120];
int main()
{
    //freopen("1.txt","r",stdin);
    int T,num;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>A[i].M;
            A[i].n=0;
        }
        int k=0,sum=0;
        strcpy(q[k],A[0].M);
        sum=strlen(q[k]);
        while(k<n-1)
        {
            int j=0,max=-1;
            for(int i=1; i<n; i++)
            {
                if(!A[i].n)
                {
                    int s=MMM(q[k],A[i].M);
                    if(s>max)max=s,j=i;
                }
            }
            A[j].n=1;
            sum+=strlen(A[j].M)-max;
            strcpy(q[++k],A[j].M);
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++)cout<<q[i]<<endl;
    }
    return 0;
}
