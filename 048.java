// RandomUsername (Nikola Jovanovic)
// Project Euler
// 048

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main048
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger sum = new BigInteger("0");
		for(int a=1; a<=1000; a++)
		{
			sum = sum.add(new BigInteger(Integer.toString(a)).pow(a));
		}
		String ret = sum.toString();
		System.out.println(ret.substring(ret.length()-10, ret.length()));
	}
}
