import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger a;
		int n;
		BigInteger d[]=new BigInteger[1200];
		d[0]=BigInteger.ONE;
		d[1]=BigInteger.valueOf(2);
		d[2]=BigInteger.valueOf(5);
		for(int i=3;i<=1000;i++)
			d[i]=d[i-1].add(d[i-1]).add(d[i-2]).add(d[i-3]);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(d[n]);
		}
	}
}
