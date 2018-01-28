/*
ID:15588661
PROG:beads
LANG:C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char M[2000];
int main()
{
    int n;
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    while(cin>>n)
    {
        int mm=0;
        cin>>M;
        int ok=0,l;
        for(int i=0; i<n; i++)
        {
            int s1=0,s2=0,ok=0;
            for(int j=0; s1<n; j++)
            {
                if(i+j>=n)l=i+j-n;
                else l=i+j;
                if(M[l]=='b'&&(!ok||ok==-1))s1++,ok=-1;
                else if(M[l]=='r'&&(!ok||ok==1))s1++,ok=1;
                else if(M[l]=='w')s1++;
                else break;
            }
            ok=0;
            for(int k=1; s2<n; k++)
            {
                if(i-k<0)l=n+i-k;
                else l=i-k;
                if(M[l]=='b'&&(!ok||ok==-1))s2++,ok=-1;
                else if(M[l]=='r'&&(!ok||ok==1))s2++,ok=1;
                else if(M[l]=='w')s2++;
                else break;
            }
            if(s1+s2>mm)mm=s1+s2;
        }
        if(mm>n)cout<<n<<endl;
        else cout<<mm<<endl;
    }
    return 0;
}
