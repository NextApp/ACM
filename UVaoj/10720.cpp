#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[12000];
int cmp(const void*_a,const void*_b)
{
    int *a=(int* )_a;
    int *b=(int *)_b;
    return *b-*a;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            int num=0,OK=1;
            for(int i=0; i<n; i++)
            {
                cin>>A[i];
                if(A[i]>n)OK=0;
                if(A[i]%2)num++;
            }
            qsort(A,n,sizeof(int),cmp);
            if(num%2)OK=0;
            if(OK)
            {
                for(int i=0; i<n-1; i++)
                {
                    if(A[i]&&OK)
                    {
                        int k=0,j;
                        for(; k<A[i]; k++)
                        {
                            j=i+1+k;
                            if(j>=n)
                            {
                                OK=0;
                                break;
                            }
                            if(A[j])A[j]--;
                            else
                            {
                                OK=0;
                                break;
                            }
                        }
                        qsort(A+i+1,n-i-1,sizeof(int),cmp);
                    }
                    else break;
                }
            }
            if(OK)cout<<"Possible"<<endl;
            else cout<<"Not possible"<<endl;
        }
    }
    return 0;
}
