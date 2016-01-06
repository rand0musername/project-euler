// RandomUsername (Nikola Jovanovic)
// Project Euler
// 029

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main029
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Set<BigInteger> s = new TreeSet<BigInteger>();
		for(int a=2; a<=100; a++)
		{
			for(int b=2; b<=100; b++)
			{
				BigInteger A = new BigInteger(Integer.toString(a));
				A = A.pow(b);
				s.add(A);
			}
		}
		System.out.println(s.size());
	}
}
