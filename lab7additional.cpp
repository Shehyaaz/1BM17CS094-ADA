//A DP solution to find the edit distance of two strings
#include <iostream>
#include <cmath>
using namespace std; 

int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int editDistDP(string str1, string str2, int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m+1][n+1]; 

	// Fill d[][] in bottom up manner 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			// If first string is empty, only option is to insert all characters of second string 
			if (i==0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to remove all characters of second string 
			else if (j==0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore it and recur for remaining string 
			else if (str1[i-1] == str2[j-1]) 
				dp[i][j] = dp[i-1][j-1]; 

			// If the last character is different, consider all possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j-1], // Insert 
								dp[i-1][j], // Remove 
								dp[i-1][j-1]); // Replace 
		} 
	} 

	return dp[m][n]; 
} 

int main() 
{ 
	string str1, str2;
	cout<<"Enter two strings : \n";
	cin>>str1>>str2; 

	cout <<"Edit Distance : "<<editDistDP(str1, str2, str1.length(), str2.length())<<endl; 

	return 0; 
} 

/*
OUTPUT :
Enter two strings : 
abbc
xbbcad
Edit Distance : 3
*/
