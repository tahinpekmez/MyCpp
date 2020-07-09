#include <iostream>
#include <climits>
using namespace std;

// i = index of current element
// prev = index of previous element included in sum
int maxSumSubseq(int arr[], int i, int n, int prev)
{
	// base case --> all elements are processed
	if (i == n)
		return 0;

	// max sum excluding the previous element
	int excl = maxSumSubseq(arr, i + 1, n, prev);
    
	// max sum including the previous element
	// for 1st element(-2), excl = -2, incl = 0
	int incl = 0; 

	// include current element only if it is not adjacent
	// to previous element considered
	if (prev + 1 != i)
		incl = maxSumSubseq(arr, i + 1, n, i) + arr[i];

	// return maximum sum we get by including or excluding
	// current item
	return max(incl, excl);
}

int main()
{
	int arr[] = {-2, 1, 3, -4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum sum is " << maxSumSubseq(arr, 0, n, INT_MIN); // OUTPUT: "Maximum sum is 8"

	return 0;
}

// ALGORITHM

/*****************************************************************
arr[] = {-2, 1, 3, -4, 5}

  incl = -2 
  excl = 0

  For i = 1 (current element is 1)
  incl =  (excl + arr[i])  = 0+1 = 1
  excl =  max(-2, 0) = 0

  For i = 2 (current element is 3)
  incl =  (excl + arr[i]) = 0+3 =3
  excl =  max(0,1) = 1

  For i = 3 (current element is -4)
  incl = (excl + arr[i]) = 1 + (-4) = -3
  excl = max(3,1) = 3

  For i = 4 (current element is 5)
  incl = (excl + arr[i]) = 3+5 = 8 ----> MAXIMUM SUM 
  excl =  max(-3,3) = 3

max(incl, excl) = 8
******************************************************/