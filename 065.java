// RandomUsername (Nikola Jovanovic)
// Project Euler
// 065

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main065
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    int ret = 0;
		BigInteger[] a = new BigInteger[200];
		a[1] = new BigInteger("2");
		a[2] = new BigInteger("3");
		for(int i = 3; i <= 100; i++)
		{
			if(i%3 == 0)
			{
				a[i] = a[i-1].multiply(new BigInteger(Integer.toString(i/3*2))).add(a[i-2]);
			}
			else
			{
				a[i] = a[i-1].add(a[i-2]);
			}
			String val = a[i].toString();
			int sum = 0;
			for(int j = 0; j < val.length(); j++)
			{
			    sum += val.charAt(j) - '0';
			}
			ret = sum;
		}
        System.out.println(ret);
	}
}
