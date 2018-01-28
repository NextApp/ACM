import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			Double r=cin.nextDouble();
			int n= cin.nextInt();
			BigDecimal re=new BigDecimal(r.toString());
			String res =re.pow(n).stripTrailingZeros().toPlainString();
			if(res.startsWith("0"))
			{
				res=res.substring(1,res.length());
			}
			System.out.println(res);
		}
	}
}
