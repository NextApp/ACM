#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m,M[50000][10],k=0;
double A[10],len[10];
void print_subset()
{
    int p[10];
    for(int i=0; i<m; i++)p[i]=i;
    sort(p,p+m);
    do
    {
        for(int i=0; i<m; i++)M[k][i]=p[i];
        k++;
    }
    while(next_permutation(p,p+m));
}
double count(double r1,double r2)
{
    return sqrt((r1+r2)*(r1+r2)-(r1-r2)*(r1-r2));
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    for(int o=0; o<n; o++)
    {
        cin>>m;
        k=0;
        print_subset();
        for(int j=0; j<m; j++)
            cin>>A[j];
        double S,T,min=1000000000.0;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<m; j++)
            {
                double mm,max=0;
                for(int r=j-1; r>=0; r--)
                {
                    mm=count(A[M[i][j]],A[M[i][r]]);
                    max=max>mm+len[M[i][r]]?max:mm+len[M[i][r]];
                }
                if(!j)
                {
                    len[M[i][j]]=A[M[i][j]];
                    S=0;
                    T=2*A[M[i][j]];
                }
                else
                {
                    len[M[i][j]]=max;
                    S=len[M[i][j]]-A[M[i][j]]<S?len[M[i][j]]-A[M[i][j]]:S;
                    T=len[M[i][j]]+A[M[i][j]]>T?len[M[i][j]]+A[M[i][j]]:T;
                }
            }
            min=T-S>min?min:T-S;
        }
        printf("%.3lf\n",min);
    }
    return 0;
}
