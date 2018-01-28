/*
package fib;
import java.math.*;
import java.util.*;
import java.util.Scanner;
public class SB {
	public static void main(String[]arg)
	{
		BigInteger d[][]=new BigInteger[110][11000];
		int T;
		Scanner cin=new Scanner(System.in);
		char []a=new char [110];
		char []b=new char [110];
		String aa,bb;
		T=cin.nextInt();
		while(cin.hasNext()&&T!=0)
		{
			bb=cin.next();
			aa=cin.next();
			a=aa.toCharArray();
			b=bb.toCharArray();
			for(int i=a.length;i>=0;i--)d[i][b.length]=BigInteger.ZERO;
			for(int j=b.length;j>=0;j--)d[a.length][j]=BigInteger.ZERO;
			for(int i=a.length-1;i>=0;i--)
				for(int j=b.length-1;j>=0;j--)
				{
				 if(a[i]==b[j])
					{
					 if(i==a.length-1)d[i][j]=d[i][j+1].add(BigInteger.ONE);
					 else d[i][j]=d[i][j+1].add(d[i+1][j+1]);
					}
					else d[i][j]=d[i][j+1];
				}
			System.out.println(d[0][0]);
			T-=1;
		}
	}

}*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[11000][110];
char a[110],b[11000];
int main()
{
    freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>b>>a;
        int lena=strlen(a);
        int lenb=strlen(b);
        for(int i=lena; i>=0; i--)
            for(int j=lenb; j>=0; j--)
            {
                if(i==lena||j==lenb)d[i][j]=0;
                else
                {
                    if(a[i]==b[j])
                    {
                        if(i==lena-1) d[i][j]=d[i][j+1]+1;
                        else d[i][j]=d[i+1][j+1]+d[i][j+1];
                    }
                    else d[i][j]=d[i][j+1];
                }
            }
        cout<<d[0][0]<<endl;
    }
    return 0;
}
