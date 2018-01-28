import java.math.*;
import java.util.*;
public class Main {
	public static void main(String args[])
	{
		BigInteger d[]=new BigInteger[10010];
		d[0]=BigInteger.ZERO;
		d[1]=BigInteger.ONE;
		d[2]=BigInteger.valueOf(3);
		for(int n=3;n<=10000;n++)
		{
			d[n]=(d[n-1].add(d[n-1])).add(BigInteger.ONE);
			for(int k=n-2;k>0;k--)
			{
				BigInteger s=BigInteger.valueOf(2).pow(n-k).subtract(BigInteger.ONE).add(d[k].add(d[k]));
				if(d[n].compareTo(s)==1)d[n]=s;
				else break;
			}
		}
		Scanner cin =new Scanner(System.in);
	while(cin.hasNext())
	{
		int n=cin.nextInt();
		System.out.println(d[n]);
	}
	}
}
