import java.math.*;
import java.util.*;
public class Main {
	public static void main(String args[])
	{
		int n;
		Scanner cin =new Scanner (System.in);
		BigInteger d[]=new BigInteger[2020];
			BigInteger s[]=new BigInteger[2020];
			d[0]=BigInteger.ZERO;
			d[1]=BigInteger.ONE;
			d[2]=BigInteger.valueOf(3);
			s[0]=BigInteger.ONE;
			for(int i=2;i<=2000;i++)
			{
				d[i]=d[i-1].add(d[i-1]).add(s[i-2]);
				s[i-1]=d[i-1].add(s[i-2]);
			}
		while(cin.hasNext())
		{
			n=cin.nextInt();
			if(n==0)break;
			System.out.println(d[n]);
		}
	}
}
