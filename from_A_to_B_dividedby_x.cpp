#include <iostream> 
using namespace std; 

// Returns count of numbers in [A B] that 
// are divisible by M. 
int DivideCount(int A, int B, int M) 
{ 
	// Add 1 explicitly as A is divisible by M 
	if (A % M == 0) 
		return (B / M) - (A / M) + 1; 

	// A is not divisible by M 
	return (B / M) - (A / M); 
} 

// Driver Code 
int main() 
{ 
	// A and B define the range, M is the divident 
	int A = 10, B = 100, M = 10; 

	// Printing the result 
	cout << DivideCount(A, B, M) << endl;  // 10

	return 0; 
} 

/***********************
ALGORITHM

A = 10, B = 100, M = 10.
Now, a = 1, b = 10.
Count = 10 - 1 = 9.
But, Count should be 9. Thus, we will
add 1 explicitly.
***********************/