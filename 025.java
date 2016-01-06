// RandomUsername (Nikola Jovanovic)
// Project Euler
// 025

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main025
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger[] a = new BigInteger[10005];

		a[1] = BigInteger.ONE;
		a[2] = BigInteger.ONE;
		for(int i=3; i<=10000; i++)
		{
			a[i] = a[i-2].add(a[i-1]);
			if(a[i].toString().length() == 1000)
			{
				System.out.println(i);
				break;
			}
		}
	}
}
