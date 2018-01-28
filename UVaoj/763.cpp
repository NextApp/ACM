
import java.io.*;
import java.math.*;
import java.util.*;
public class Main {
	public static BigInteger result(char []arg,BigInteger []M)
	{
		BigInteger sum=BigInteger.ZERO;
		for(int i=arg.length-1;i>=0;i--)
		sum=sum.add(M[arg.length-1-i].multiply((BigInteger.valueOf(arg[i]-'0'))));
		return sum;
	}
	public static void change(BigInteger n,BigInteger []M)
	{
		int ok=0;
		for(int i=105;i>=0;i--)
		{
			if(M[i].compareTo(n)<1)
			{
				n=n.subtract(M[i]);
				ok=1;
				System.out.print(1);
			}
			else if(ok==1)
			{
			System.out.print(0);
			}
		}
		System.out.println();
	}
	public  static void main(String []arg)
	{
		BigInteger M[]=new BigInteger[120];
		M[0]=BigInteger.ONE;
		M[1]=BigInteger.valueOf(2);
		for(int i=2;i<=105;i++)
			M[i]=M[i-1].add(M[i-2]);
		Scanner cin =new Scanner(System.in);
		char [] a=new char [120];
		char []b=new char [120];
		String aa,bb;
		int id=0;
		while(cin.hasNext())
		{
			if(id++!=0)System.out.println();
			aa=cin.next();
			bb=cin.next();
			a=aa.toCharArray();
			b=bb.toCharArray();
			BigInteger sum,x,y;
			if(a[0]=='0')x=BigInteger.ZERO;
			else x=result(a,M);
			if(b[0]=='0')y=BigInteger.ZERO;
			else y=result(b,M);
			sum=x.add(y);
			if(sum.compareTo(BigInteger.valueOf(0))==0)System.out.println(0);
			else change(sum,M);
		}
	}
}
