#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define Max 1000
#define ds 10
using namespace std;
char a[Max],b[Max],c[Max];
int lena,lenb;
int Q0(char a[])
{
    int i=0;
    for(; a[i]; i++)if(a[i]!='0')break;
    strcpy(a,a+i);
}
int Strcmp(char a[],char b[])
{
    Q0(a),Q0(b);
    int len1=strlen(a);
    int len2=strlen(b);
    if(len1>len2)return 1;
    else if(len1<len2)return -1;
    else
    {
        for(int i=0; a[i]; i++)
        {
            if(a[i]>b[i])return 1;
            else if(a[i]<b[i])return -1;
        }
        return 0;
    }
}
int JJJ(char a[],char b[],char c[])
{
    int ok=0;
    if(strcmp(a,b)<0)ok=1;
    for(int i=lenb-1; i>=0; i--)
    {
        if(a[i+ok]>=b[i])a[i+ok]=a[i+ok]-b[i];
        else a[i+ok-1]--,a[i+ok]=a[i+ok]+10-b[i];
    }
    for(int i=ok; i<lenb+ok; i++)
        a[i]+='0';
    int len=strlen(a);
    if(ok)c[lena-len+1]++;
    else c[lena-len]++;
}
int Chufa(char a[],char b[],char res[])
{
    Q0(a),Q0(b);//对除数和被除数进行除前导零处理
    lenb=strlen(b);
    lena=strlen(a);
    if(!lenb)cout<<"wrong!!!"<<endl;
    else if(!lena)cout<<"0"<<endl;
    else
    {
        int i=0;
        for(; i<ds; i++)a[i+lena]='0';
        a[i+lena]='\0';
        lena+=ds;
        for(i=0; i<1000; i++)res[i]=0;
        int k=lena-lenb+1;
        if(k<=ds)k=ds+1;
        while(Strcmp(a,b)>=0)
            JJJ(a,b,res);
        for(i=0; i<k; i++)
            res[i]+='0';
        res[i]='\0';
        char cc[Max];/*对商进行小数点处理*/
        strcpy(cc,res+k-ds);
        res[k-ds]='.';
        strcpy(res+k-ds+1,cc);
        res[k+1]='\0';
        if(res[0]=='0'&&res[1]!='.')strcpy(res,res+1);
    }
}
int main()
{
    while(cin>>a>>b)
    {
        Chufa(a,b,c);
        cout<<c<<endl;
    }
    return 0;
}
