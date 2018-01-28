import java.util.*;
import java.math.*;
import java.util.Scanner;
public class Main {
	public static void main(String arg[])
	{
		BigInteger n;
		Scanner cin =new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextBigInteger();
			if(n.compareTo(BigInteger.ZERO)==0)
			{
				System.out.println(1);
			}
			else
			System.out.println((n.multiply(n.subtract(BigInteger.ONE)).add(BigInteger.valueOf(2))));
		}
	}
}
