#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define N 31268
using namespace std;
long long S[32000]= {0,1};
int A[32000]= {0,1};
void bfread()
{
    int mm=(1<<31)-1;
    for(int i=2;; i++)
    {
        A[i]=A[i-1]+(int)log10((double)i)+1;
        S[i]=S[i-1]+A[i];
        if(S[i]>mm)break;
    }
}
int  b_search(int m,int *k)
{
    int a=0,b=N;
    while(a<b)
    {
        *k=(a+b)/2;
        if(S[*k]<=m&&m<S[*k+1])return m-S[*k];
        else if(m<S[*k])b=*k;
        else a=*k;
    }
}
int B_search(int b,int s)
{
    int a=0;
    while(a<=b)
    {
        int k=(a+b)/2;
        if(A[k]<=s&&s<A[k+1])
        {
            int t=s-A[k];
            if(!t)cout<<k%10<<endl;
            else
            {
                k++;
                int m;
                t=(int)(log10(double(k)))+1-t;
                cout<<(int)(k/pow(10,t))%10<<endl;
            }
            return 0;
        }
        else if(s<A[k])b=k-1;
        else a=k+1;
    }
}
void seek(int m)
{
    int k,s;
    s=b_search(m,&k);
    if(!s)cout<<k%10<<endl;
    else B_search(k+1,s);
}
int main()
{
    //freopen("1.txt","r",stdin);
    bfread();
    int num,n;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        seek(n);
    }
    return 0;
}
