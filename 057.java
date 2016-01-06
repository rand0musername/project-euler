// RandomUsername (Nikola Jovanovic)
// Project Euler
// 057

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main057
{
	private static int Digits(BigInteger x)
	{
		int ret = 0;
		while(!x.equals(BigInteger.ZERO))
		{
			x = x.divide(new BigInteger("10"));
			ret++;
		}
		return ret;
	}

	static BigInteger[] F = new BigInteger[3000];
	public static void main (String[] args) throws java.lang.Exception
	{
		int ret = 0;

		F[1] = new BigInteger("2");
		F[2] = new BigInteger("3");
		for(int i=2; i<=1000; i++)
		{
			F[i*2-1] = F[i*2-2].add(F[i*2-3]);
			F[i*2] = F[i*2-3].add(F[i*2-1]);
			if(Digits(F[2*i]) > Digits(F[2*i-1]))
				ret++;
		}

		System.out.println(ret);
	}
}
