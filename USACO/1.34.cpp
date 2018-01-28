/*
ID :15588661
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int num,a[20],S[20],sum=0;
    cin>>num;
    memset(S,0,sizeof(S));
    for(int i=0; i<num; i++)
    {
        cin>>a[i];
        S[a[i]]=1;
    }
    int M[10];
    for(int k=0; k<num; k++)
        for(int m=0; m<num; m++)
            for(int h=0; h<num; h++)
                for(int i=0; i<num; i++)
                    for(int j=0; j<num; j++)
                    {
                        int s=100*a[i]*a[h]+10*a[i]*a[m]+a[i]*a[k];
                        int t=1000*a[j]*a[h]+100*a[j]*a[m]+10*a[j]*a[k];
                        int ok=1,o=s+t,ss=0;
                        if(s>999||t>9999||o>9999)ok=0;
                        o/=10;
                        t/=10;
                        while(ss<3)
                        {
                            if(!S[s%10]||!S[t%10]||!S[o%10])ok=0;
                            s/=10,t/=10,o/=10;
                            ss++;
                        }
                        if(ok)sum++;

                    }
    cout<<sum<<endl;
    return 0;
}
