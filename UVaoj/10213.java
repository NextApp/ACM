import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger a;
		int T;
			T=cin.nextInt();
			while(T>0)
			{
			    a=cin.nextBigInteger();
				BigInteger n=BigInteger.ZERO;
				if(a.compareTo(BigInteger.valueOf(3))>=0)
				{
					n=a.multiply(a.subtract(BigInteger.ONE)).multiply(a.subtract(BigInteger.valueOf(2)));
			        n=(n.multiply(a.subtract(BigInteger.valueOf(3)))).divide(BigInteger.valueOf(24));
				}
				if(a.compareTo(BigInteger.valueOf(1))>=0)n=n.add((a.multiply(a.subtract(BigInteger.ONE))).divide(BigInteger.valueOf(2)));
				n=n.add(BigInteger.ONE);
				System.out.println(n);
			    T--;
			}
	}
}
