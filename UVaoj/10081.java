import java.math.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		BigDecimal d[][][] = new BigDecimal[12][105][12];
		BigDecimal w[][]=new BigDecimal[12][105];
		for (int k = 0; k <= 9; k++)
			for (int x = 0; x <= 9; x++)
				d[k][1][x] = BigDecimal.ONE;
		for (int k = 0; k <= 9; k++)
			for (int n = 1; n <= 100; n++) {
				BigDecimal sum = BigDecimal.ZERO,p=BigDecimal.valueOf(k+1).pow(n);
				for (int t = 0; t <= k&&n>1; t++) {
					int x = t - 1, y = t + 1, z = t;
					d[k][n][t] = d[k][n - 1][z];
					if (y <= k)d[k][n][t]=d[k][n][t].add(d[k][n - 1][y]);
					if (x >= 0)d[k][n][t]=d[k][n][t].add(d[k][n - 1][x]);
					sum=sum.add(d[k][n][t]);
				}
				if(n==1)sum=BigDecimal.valueOf(k+1);
				sum=sum.multiply(BigDecimal.valueOf(100.));
		    	w[k][n]=sum.divide(p, 5,BigDecimal.ROUND_HALF_UP);
			}
		int n,m;
		while (cin.hasNext()) {
			n = cin.nextInt();
			m = cin.nextInt();
			System.out.println(w[n][m]);
		}
	}
}
