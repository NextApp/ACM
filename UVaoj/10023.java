import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;
import java.util.*;
public class Main
{
    public static void main(String[] arg)
    {
        String M;
        Scanner cin=new Scanner(System.in);
        int m[]=new int [120];
        int j=1;
        for(int i=1; i<100; i++)
        {
            if((j+1)*(j+1)==i)j++;
            m[i]=j;
        }
        int t,tt;
        t=cin.nextInt();
        for(tt=0; tt<t; tt++)
        {
            if(tt!=0)System.out.println();
            M=cin.next();
            int len=M.length(),d,aa,i;
            BigInteger c,mul,b,a;
            if(len%2==1)
            {
                d=M.charAt(0)-'0';
                i=1;
            }
            else
            {
                d=(M.charAt(0)-'0')*10+M.charAt(1)-'0';
                i=2;
            }
            aa=m[d];
            mul=BigInteger.valueOf(d-aa*aa);
            a=BigInteger.valueOf(aa);
            for(; i<=len-2; i+=2)
            {
                c=mul.multiply(BigInteger.valueOf(100)).add(new BigInteger(M.substring(i,i+2)));
                b=c.divide(a.multiply(BigInteger.valueOf(20)));
                BigInteger s=c.add(BigInteger.valueOf(1));
                while(s.compareTo(c)==1)
                {
                    s=b.multiply((a.multiply(BigInteger.valueOf(20)).add(b)));
                    if(s.compareTo(c)==1)
                        b=b.subtract(BigInteger.valueOf(1));
                }
                mul=c.subtract(s);
                a=a.multiply(BigInteger.valueOf(10)).add(b);
            }
            System.out.println(a);
        }
    }
}
