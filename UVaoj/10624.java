
import java.math.*;
import java.util.*;
public class Main {
	static int m=0,ok=1,id=1,vis[]=new int[40];
	static int q=0;
	static BigInteger D[][]=new BigInteger[40][40];
	static void dfs(BigInteger n,int s)
	{
		if(ok==0)return ;
		if(m<=s)
		{
			ok=0;
			System.out.println(n);
		}
		BigInteger w=n.multiply(BigInteger.TEN).mod(BigInteger.valueOf(s+1));
		BigInteger d=w;
		if(w!=BigInteger.ZERO)d=BigInteger.valueOf(s+1).subtract(w);
		while(d.compareTo(BigInteger.TEN)<0)
		{
	     	 BigInteger l=n.multiply(BigInteger.TEN).add(d);
	    	 dfs(l,s+1);
	    	 d=d.add(BigInteger.valueOf(s+1));
		}
	}
	static BigInteger o=BigInteger.ZERO;
	static int ll=1,nn=1;
	static void dfs1(BigInteger n)
	{
		BigInteger w=BigInteger.TEN.pow(nn-1);
		BigInteger z=BigInteger.TEN.pow(nn);
		BigInteger k=BigInteger.ONE;
		for(; w.compareTo(z)<0;w=w.add(k))
		{
		  if(w.mod(n)==BigInteger.ZERO)break;
		}
		k=n;
		for(;w.compareTo(z)<0;w=w.add(k))
		{
			ok=1;
			dfs(w,nn);
			if(ok==0)break;
		}
	}
	public static void main(String arg[])
	{
		Scanner cin=new Scanner(System.in);
     int x,y,T;
        T=cin.nextInt();
	while(T>0)
	{
		x=cin.nextInt();
		y=cin.nextInt();
		m=y;
		nn=x;
		ll=1;
		ok=1;
		System.out.print("Case ");
		System.out.print(id++);
		System.out.print(": ");
		if(m>=nn)
    	dfs1(BigInteger.valueOf(nn));
    	if(ok==1)
    	{
    		System.out.println("-1");
    	}
		T--;
	}
	}
}
