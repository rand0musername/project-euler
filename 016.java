// RandomUsername (Nikola Jovanovic)
// Project Euler
// 016

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main016
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger x = new BigInteger("2");
		String s = x.pow(1000).toString();

		int ret = 0;
		for(int i=0; i<s.length(); i++)
		{
			ret += s.charAt(i) - '0';
		}

		System.out.println(ret);
	}
}
