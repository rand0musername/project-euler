// RandomUsername (Nikola Jovanovic)
// Project Euler
// 020

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main020
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger x = new BigInteger("1");
		for(int i = 1; i <= 100; i++)
		{
			x = x.multiply(new BigInteger(Integer.toString(i)));
		}
		String s = x.toString();

		int ret = 0;
		for(int i=0; i<s.length(); i++)
		{
			ret += s.charAt(i) - '0';
		}

		System.out.println(ret);
	}
}
