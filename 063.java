// RandomUsername (Nikola Jovanovic)
// Project Euler
// 063

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// len(a^1) = 1, len grows faster so once we lose it it's over
		int ret = 0;
		for(int a = 1; a <= 9; a++)
		{
			BigInteger x = BigInteger.valueOf(a);
			ret++;
			while(x.toString().length() < x.multiply(BigInteger.valueOf(a)).toString().length())
			{
				ret++;
				x = x.multiply(BigInteger.valueOf(a));
			}
		}
		System.out.println(ret);
	}
}
