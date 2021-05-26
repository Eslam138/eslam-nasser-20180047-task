// C/C++ program to solve fractional Knapsack Problem 
#include <bits/stdc++.h> 

using namespace std; 
// Structure for an item which stores weight and 
// corresponding value of Item 
struct item 
{ 
	int V, W; 

	// Constructor 
	item(int V, int W) 
		: V(V) 
		,W(W) 
	{ 
	} 
}; 

// Comparison function to sort Item according to val/weight 
// ratio 
bool Comparison(struct item a, struct item b) 
{ 
	double R1 = (double)a.V / (double)a.W; 
	double R2 = (double)b.V / (double)b.W; 
	return R1 > R2; 
}
// Main greedy function to solve problem 
double fracKnapsack(int weight, struct item arr[], int n) 
{ 
	// sorting Item on basis of ratio 
	sort(arr, arr + n, Comparison);

	int cw = 0; // Current weight in knapsack 
	double result = 0.0; // Result (value in Knapsack) 

	// Looping through all Items 
	for (int i = 0; i < n; i++) 
	{ 
		// If adding Item won't overflow, add it completely 
		if (cw + arr[i].W <= weight) 
		{ 
			cw += arr[i].W; 
			result += arr[i].V; 
		} 

		// If we can't add current Item, add fractional part 
		// of it 
		else
		{ 
			int remain = weight- cw; 
			result
				+= arr[i].V 
				* ((double)remain / (double)arr[i].W); 
			break; 
		} 
	} 

	// Returning final value 
	return result; 
} 

// Driver code 
int main() 
{ 
	int Weight = 50; // Weight of knapsack 
	item array[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; 

	int n = sizeof(array) / sizeof(array[0]); 

	// Function call 
	cout << "Maximum value we can obtain = "
		<< fracKnapsack(Weight, array, n); 
	return 0; 
}

