/*
ID: 15588661
PROG: calfflac
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char A[30000],B[30000];
int num,sum=0,t=0,ii=0,jj=0,len;
int MM(char a[],char b[])
{
    for(int i=0; a[i]; i++)
        if(a[i]<='Z'&&a[i]>='A')b[i]=a[i]+'a'-'A';
        else b[i]=a[i];
}
int SSS(int ix,int iy,int ok)
{
    while(1)
    {
        if(ix<0||iy==len||A[ix]!=A[iy])
        {
            if(num>t)
            {
                t=num;
                if(!ok)sum=2*(num-1)+1;
                else sum=2*num;
                ii=ix+1,jj=iy-1;
            }
            break;
        }
        else num++;
        ix--;
        iy++;
        while(ix>=0&&(A[ix]<'a'||A[ix]>'z'))ix--;
        while(iy<len&&(A[iy]<'a'||A[iy]>'z'))iy++;
    }
}
int main()
{
    freopen("calfflac.in","r",stdin);
     freopen("calfflac.out","w",stdout);
   // freopen("1.txt","r",stdin);
    int In,i=0;
    while((In=getchar())!=EOF)B[i++]=In;
    B[i]='\0';
    MM(B,A);
    len=i;
    for(int i=0; A[i]; i++)
    {
        if(A[i]<'a'||A[i]>'z')continue;
        num=0;
        SSS(i,i,0);
        num=0;
        int m=i+1;
        while(m<len&&(A[m]<'a'||A[m]>'z'))m++;
        SSS(i,m,1);
    }
    while(ii>=0&&(A[ii]<'a'||A[ii]>'z'))ii++;
    while(jj<len&&(A[jj]<'a'||A[jj]>'z'))jj--;
    cout<<sum<<endl;
    for(int i=ii; i<=jj; i++)
        cout<<B[i];
    cout<<endl;
    return 0;
}
