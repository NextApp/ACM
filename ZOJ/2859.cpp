#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node
{
    int right,left,mm,len;
} A[340][1200];
int n,a[350][350],nu=0;
void BuildTree(int l,int r,int x,int y)
{
    A[x][y].right=r;
    A[x][y].left=l;
    A[x][y].len=r-l;
    if(A[x][y].len<=0)return;
    if(A[x][y].len>1)
    {
        int s=(r+l)>>1;
        BuildTree(l,s,x,y<<1);
        BuildTree(s,r,x,(y<<1)+1);
        A[x][y].mm=min(A[x][y<<1].mm,A[x][(y<<1)+1].mm);
    }
    else A[x][y].mm=a[x-1][nu++];
}
int Search(int l,int r,int x,int y)
{
    if(l==A[x][y].left&&r==A[x][y].right) return A[x][y].mm;
    int s= (A[x][y].right + A[x][y].left)>>1;
    if(l<s&&s<r)
        return min(Search(l,s,x,y<<1),Search(s,r,x,(y<<1)+1));
    else if(r<=s)
        return Search(l,r,x,y<<1);
    else if(l>=s)
        return Search(l,r,x,(y<<1)+1);
    else return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        for(int i=1; i<=n; i++)
        {
            nu=0;
            BuildTree(1,n+1,i,1);
        }
        int m,x1,y1,x2,y2;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int mm=1000000000;
            for(int i=x1; i<=x2; i++)
                mm=min(Search(y1,y2+1,i,1),mm);
            printf("%d\n",mm);
        }
    }
    return 0;
}
