import java.math.*;
import java.util.*;
public class Main {

	static BigInteger d[][]=new BigInteger[30][30];
	public static int f(int n,int k)
	{
		int sum=0,a=1;
		for(int i=0;i<=n;i++)
			{
			sum+=a;
			a*=k;
			}
		return sum;
	}
	public static BigInteger C(int a,int b)
	{
		BigInteger sum=BigInteger.ONE;
		for(int i=1;i<=a;i++)
		{
			sum=sum.multiply(BigInteger.valueOf(b-i+1));
			sum=sum.divide(BigInteger.valueOf(i));
		}
		return sum;
	}
	public static BigInteger S(int k)
	{
		BigInteger sum=BigInteger.ONE;
		for(int i=2;i<=k;i++)
			sum=sum.multiply(BigInteger.valueOf(i));
		return sum;
	}
	public static BigInteger dp(int k,int n)
	{
		if(d[n][k].compareTo(BigInteger.ZERO)==1)
			return d[n][k];
	BigInteger sum=BigInteger.ONE;
		int a=f(n-1,k),b=f(n,k)-1;
		while(a>0)
		{
			sum=sum.multiply(C(a,b)).multiply(dp(k,n-1));
			if(a==b)break;
			b-=a;
		}
		d[n][k]=sum;
		return d[n][k];
	}
	public static void main(String args[])
	{
			for(int i=1;i<=21;i++)
		    for(int j=1;i*j<=21;j++)
		    d[i][j]=BigInteger.ZERO;
			for(int i=1;i<=21;i++)
			{
				BigInteger sum=BigInteger.ONE;
				for(int j=1;j<=i;j++)
					sum=sum.multiply(BigInteger.valueOf(j));
				d[1][i]=sum;
			}
			Scanner cin =new Scanner(System.in);
			while(cin.hasNext())
			{
				int n,k;
				k=cin.nextInt();
				n=cin.nextInt();
				BigInteger m=dp(k,n);
				System.out.println(m);
			}
	}
}
