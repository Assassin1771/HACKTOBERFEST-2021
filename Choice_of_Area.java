/*package whatever //do not write package name here */
import java.util.*;
import java.io.*;

class GFG {
// Java code to get maximum survival time

// class to represent an area
static class area
{
	// increment or decrement in A and B
	public int a, b;
	public area(int a, int b){
	this.a = a;
	this.b = b;
	}
};

// class to represent pair
static class Pair{
	public int first,second;
	public Pair(int first,int second){
	this.first = first;
	this.second = second;
	}
}


// Utility method to get maximum of 3 integers
static int max(int a, int b, int c)
{
	return Math.max(a, Math.max(b, c));
}

// Utility method to get maximum survival time
static int maxSurvival(int A, int B, area X, area Y, area Z,
						int last, HashMap<Pair, Integer> memo)
{
	// if any of A or B is less than 0, return 0
	if (A <= 0 || B <= 0)
	return 0;
	Pair cur = new Pair(A, B);

	// if already calculated, return calculated value
	if (memo.containsKey(cur))
	return memo.get(cur);

	int temp = 0;

	// step to areas on basis of last choose area
	switch(last)
	{
	case 1:
		temp = 1 + Math.max(maxSurvival(A + Y.a, B + Y.b,
										X, Y, Z, 2, memo),
							maxSurvival(A + Z.a, B + Z.b,
										X, Y, Z, 3, memo));
		break;
	case 2:
		temp = 1 + Math.max(maxSurvival(A + X.a, B + X.b,
										X, Y, Z, 1, memo),
							maxSurvival(A + Z.a, B + Z.b,
										X, Y, Z, 3, memo));
		break;
	case 3:
		temp = 1 + Math.max(maxSurvival(A + X.a, B + X.b,
										X, Y, Z, 1, memo),
							maxSurvival(A + Y.a, B + Y.b,
										X, Y, Z, 2, memo));
		break;
	}

	// store the result into map
	memo.put(cur,temp);

	return temp;
}

// method returns maximum survival time
static int getMaxSurvivalTime(int A, int B, area X, area Y, area Z)
{
	if (A <= 0 || B <= 0)
	return 0;
	HashMap<Pair,Integer> memo = new HashMap<>();

	// At first, we can step into any of the area
	return
	max(maxSurvival(A + X.a, B + X.b, X, Y, Z, 1, memo),
		maxSurvival(A + Y.a, B + Y.b, X, Y, Z, 2, memo),
		maxSurvival(A + Z.a, B + Z.b, X, Y, Z, 3, memo));
}

// Driver Code
public static void main(String args[])
{
	area X = new area(3, 2);
	area Y = new area(-5, -10);
	area Z = new area(-20, 5);

	int A = 20;
	int B = 8;
	System.out.println(getMaxSurvivalTime(A, B, X, Y, Z));
}
}


