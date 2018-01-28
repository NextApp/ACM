#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int num;
    //freopen("1.txt","r",stdin);
    int M[200];
    cin>>num;
    for(int i=0; i<num; i++)
    {
        char a[105];
        cin>>a;
        int sum=0,len=strlen(a),O=0,oo=0,OK=1;
        memset(M,0,sizeof(M));
        for(int k=0;a[k];k++)M[a[k]]++;
        for(int k='a';k<='z';k++)
        {
            if(M[k]%2)O++;
        }
        if(O>1)OK=0;
        for(int j=0; j<len/2; j++)
        {
            int ok=0,l=len-j-1+oo;
            for(int k=l; k>j; k--)
            {
                if(a[j]==a[k])
                {
                    char temp=a[k];
                    for(int m=k;m<l;m++)a[m]=a[m+1];
                    a[l]=temp;
                    sum+=l-k;
                    ok=1;
                    break;
                }
            }
            if(!ok)
            {
                a[j]='*';
                oo++;
            }
        }
        for(int j=0;j<len;j++)if(a[j]=='*')sum+=fabs(len/2-j);
        if(oo<=1&&OK)cout<<sum<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
