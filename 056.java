// RandomUsername (Nikola Jovanovic)
// Project Euler
// 056

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main056
{
	private static int digitalSum(BigInteger n)
	{
		String s = n.toString();
		int ret = 0;
		for(int i = 0; i < s.length(); i++)
		{
			ret += s.charAt(i) - '0';
		}
		return ret;
	}

	public static void main (String[] args) throws java.lang.Exception
	{
		int ret = 0;

		for(int a = 1; a < 100; a++)
		{
			for(int b = 0; b < 100; b++)
			{
				BigInteger n = BigInteger.valueOf(a);
				n = n.pow(b);
				ret = Math.max(ret, digitalSum(n));
			}
		}
		System.out.println(ret);
	}
}
