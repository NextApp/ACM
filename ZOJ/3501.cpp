#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct T
{
    char a[10];
    char b[50];
} A[11000];
char X1[4][10]= {"I","X","C","M"};
char X2[4][10]= {"II","XX","CC","MM"};
char X3[4][10]= {"III","XXX","CCC","MMM"};
char X4[4][10]= {"IV","XL","CD"};
char X5[4][10]= {"V","L","D"};
char X6[4][10]= {"VI","LX","DC"};
char X7[4][10]= {"VII","LXX","DCC"};
char X8[4][10]= {"VIII","LXXX","DCCC"};
char X9[4][10]= {"IX","XC","CM"};
void change(int s)
{
    int len=strlen(A[s].a);
    char b[100];
    int l=0;
    for(int i=0; i<len; i++)
        if(A[s].a[i]=='1')
        {
            strcpy(b+l,X1[len-i-1]);
            l+=strlen(X1[len-i-1]);
        }
        else if(A[s].a[i]=='2')
        {
            strcpy(b+l,X2[len-i-1]);
            l+=strlen(X2[len-i-1]);
        }
        else if(A[s].a[i]=='3')
        {
            strcpy(b+l,X3[len-i-1]);
            l+=strlen(X3[len-i-1]);
        }
        else if(A[s].a[i]=='4')
        {
            strcpy(b+l,X4[len-i-1]);
            l+=strlen(X4[len-i-1]);
        }
        else if(A[s].a[i]=='5')
        {
            strcpy(b+l,X5[len-i-1]);
            l+=strlen(X5[len-i-1]);
        }
        else if(A[s].a[i]=='6')
        {
            strcpy(b+l,X6[len-i-1]);
            l+=strlen(X6[len-i-1]);
        }
        else if(A[s].a[i]=='7')
        {
            strcpy(b+l,X7[len-i-1]);
            l+=strlen(X7[len-i-1]);
        }
        else if(A[s].a[i]=='8')
        {
            strcpy(b+l,X8[len-i-1]);
            l+=strlen(X8[len-i-1]);
        }
        else if(A[s].a[i]=='9')
        {
            strcpy(b+l,X9[len-i-1]);
            l+=strlen(X9[len-i-1]);
        }
        strcpy(A[s].b,b);
}
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    return strcmp(a->b,b->b);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int j=0; j<n; j++)
        {
            cin>>A[j].a;
            change(j);
        }
        qsort(A,n,sizeof(A[0]),cmp);
        for(int i=0;i<n-1;i++)
            cout<<A[i].a<<' ';
        cout<<A[n-1].a<<endl;
    }
    return 0;
}
