import java.math.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		BigInteger d[][] = new BigInteger[155][155];
		int N=151;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
		d[i][j]=BigInteger.ZERO;
		for(int i=0;i<N;i++)
			d[0][i]=BigInteger.ONE;
		for(int i=1;i<N;i++)
			for(int j=1;j<N;j++)
				{
				for(int k=1;k<=i;k++)
					d[i][j]=d[i][j].add(d[k-1][j-1].multiply(d[i-k][j]));
				}
		int n,m;
		while (cin.hasNext()) {
			n = cin.nextInt();
			m = cin.nextInt();
			if(n%2==1){System.out.println(0);}
			else
			{
				System.out.println(d[n/2][m].subtract(d[n/2][m-1]));
			}
		}
	}
}
