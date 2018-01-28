package sdf;

import java.io.*;
import java.math.*;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner in =new Scanner (System.in);
		BigInteger N =BigInteger.TEN.pow(100);
		while(in.hasNext())
		{
			int n=in.nextInt();
			BigInteger sum=BigInteger.ONE,t;
			t=sum;
			for(int k=1;2*k<=n;k++)
			{
				t=t.multiply(BigInteger.valueOf((n-2*k+1)*(n-2*k+2))).divide(BigInteger.valueOf(k*(k+1)));
				sum=sum.add(t);
			}
			sum=sum.mod(N);
			System.out.println(sum);
		}
	}

}
