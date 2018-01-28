#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 1200
using namespace std;
char M[N];
long long m[105];
int main()
{
    int j=1;
    for(int i=1; i<100; i++)
    {
        if((j+1)*(j+1)==i)j++;
        m[i]=j;
    }
    while(cin>>M)
    {
            long long len=strlen(M),a,c,mul,i,b;
            if(len%2)mul=M[0]-'0',i=1;
            else mul=(M[0]-'0')*10+M[1]-'0',i=2;
            a=m[mul];
            mul-=a*a;
            for(; i<len; i+=2)
            {
                c=mul*100+(M[i]-'0')*10+M[i+1]-'0';
                cout<<i<<endl;
                b=c/(20*a);
                long long s=c+1;
                /*while(1)
                {
                   long long s=b*(20*a+b);
                    if(s<=c)
                    {
                        mul=c-s;
                        break;
                    }
                    else b--;
                }*/
                while(s>c)
                {
                    s=b*(20*a+b);
                    if(s>c)b--;
                }
                mul=c-s;
                a=a*10+b;
            }
            cout<<a<<endl;
    }
    return 0;
}
