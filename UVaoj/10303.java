import java.util.Scanner;
import java.math.*;
import java.util.*;
public class Main {
	public static void main(String[]arg)
	{
		BigInteger a[]=new BigInteger[1100];
		a[0]=a[1]=BigInteger.valueOf(1);
		int n;
		for(n=2;n<=1000;n++)
		{
			BigInteger s=BigInteger.ZERO;
			for(int i=1;n-i>=n/2;i++)
			s=s.add((a[n-i].multiply(a[i-1])).multiply(BigInteger.valueOf(2)));
			if(n%2==1)s=s.subtract(a[n/2].multiply(a[n/2]));
			a[n]=s;
		}
		Scanner cin =new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(a[n]);
		}
	}
}
