#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char S[3000],B[3000];
int SSS(char C[],int i)
{
    int k=0,j=0,a=0;
    for(; S[i]; i++)
    {
        int ok=0;
        for(; B[j]; j++)
        {
            if(S[i]==B[j])
            {
                ok=1;
                C[k++]=S[i];
                j++;
                break;
            }
        }
        if(!ok)j=a;
        else a=j;
    }
    return k;
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>S>>B)
    {
        int max=0;
        char C[2000],D[2000];
        for(int i=0;S[i]; i++)
        {
            int k=SSS(D,i);
            if(max<k)
            {
                max=k;
                strcpy(C,D);
            }
        }
        C[max]='\0';
        sort(C,C+max);
        cout<<C<<endl;
    }
    return 0;
}
