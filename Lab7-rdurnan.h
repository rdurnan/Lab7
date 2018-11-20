// Lab7-rdurnan.h
// Ryan Durnan
// COSC 2030
// Lab7
// 12 Nov 2018

#ifndef _LAB7_RDURNAN_H_
#define _LAB7_RDURNAN_H_

#include <vector>

using std::vector;


// For bubble:
//	https://www.geeksforgeeks.org/bubble-sort/
// For insertion:
//	https://www.geeksforgeeks.org/insertion-sort/
// For selection:
//	https://www.geeksforgeeks.org/selection-sort/
// For merge:
//	https://www.geeksforgeeks.org/merge-sort/
// For quick:
//	https://www.geeksforgeeks.org/quick-sort/


// Sorting function that repeatedly swaps adjacent
// elements if they are in the wrong order.
void bubble(vector<double> & numbers)
{
	bool swapped;	// Keep track if elements have been swapped
	for (int h = 0; h < numbers.size(); h++)	// Look through each element in the vector
	{
		swapped = false;	// Reset the tracking variable
		for (int i = 0; i < numbers.size(); i++)	// Loop through vector for every element
		{
			double temp;	// Keep a temporary variable for the possible swap
			if (i == (numbers.size() - 1))	
			{
				break;	// Break if the end of the vector has been reached
			}
			else if (numbers[i] > numbers[i + 1])	// If the current number is greater than the next...
			{
				temp = numbers[i];	// Store current number
				numbers[i] = numbers[i + 1];	// Swap the current and next numbers
				numbers[i + 1] = temp;	// Put the stored number in the next element
				swapped = true;	// Indicate that a number has been swapped. Another loop is needed to check if everything is in order.
			}
		}
		if (swapped == false)
		{
			break;	// Break if the vector is in order.
		}
	}
}

// Sorting function picks an element in a vector
// and places it in the appropriate spot.
void insertion(vector<double> & numbers)
{
	for (int i = 1; i < numbers.size(); i++)	// Look through the vector
	{
		double card = numbers[i];	// Track the value of the current element
		int j = i - 1;	// Index of the element to be checked

		while (j >= 0 && numbers[j] > card)	// Keep checking if the element being checked is greater than the current
		{
			numbers[j + 1] = numbers[j];	// Move the greater element ahead
			j = j - 1;	// Modify the index of the element being checked
		}
		numbers[j + 1] = card; // Make sure that the current element is placed back into vector
	}
}

// Sorting function that repeatedly finds the 
// minimum value in a vector and inserts that
// that value at the appropriate index.
void selection(vector<double> & numbers)
{
	int min_idx;	// Keep track of the index with the minimum value
	double temp;	// Prepare a temporary variable for a possible swap
	for (int i = 0; i < numbers.size() - 1; i++)	// Look through each element in the vector
	{
		min_idx = i;	// Set the minimum index to the current index being checked
		for (int j = i + 1; j < numbers.size(); j++)	// Look through all elements following current element
		{
			if (numbers[j] < numbers[min_idx])	// Check if the element being looked at is less than the current minimum
				min_idx = j;					// Update minimum index if necessary
		}
		temp = numbers[min_idx];		// Store the value at the minimum index
		numbers[min_idx] = numbers[i];	// Swap the value at the minimum index with the value at the current index
		numbers[i] = temp;				// Place the stored value at the current index
	}
}

// Function used by actual merge sort function
// to divide a vector into smaller vectors
void merge(vector<double> & number, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<double> L, R;
	L.resize(n1);
	R.resize(n2);

	for (i = 0; i < n1; i++)
		L[i] = number[l + i];
	for (j = 0; j < n2; j++)
		R[j] = number[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			number[k] = L[i];
			i++;
		}
		else
		{
			number[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		number[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		number[k] = R[j];
		j++;
		k++;
	}
}

// Sorting function that divides a vector into
// several smaller vectors. When all the smaller
// vectors include only one element, those vectors
// are merged according to value.
void mergeSort(vector<double> & number, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(number, l, m);
		mergeSort(number, m + 1, r);

		merge(number, l, m, r);
	}
}

// Function used by actual quick sort function
// to divide a vector at a partition
int partition(vector<double> & number, int low, int high)
{
	double pivot = number[high]; 
	int i = (low - 1);  
	double temp;
	for (int j = low; j <= high - 1; j++)
	{ 
		if (number[j] <= pivot)
		{
			i++;
			temp = number[i];
			number[i] = number[j];
			number[j] = temp;
		}
	}
	temp = number[i + 1];
	number[i + 1] = number[high];
	number[high] = temp;
	return (i + 1);
}

// Sorting function that pivots a vector at a
// specific partion. All elements smaller than
// the pivot are sorted to the left. All elements
// greator than the pivot are sorted to the right.
void quickSort(vector<double> & number, int low, int high)
{
	if (low < high)
	{
		int pi = partition(number, low, high);

		quickSort(number, low, pi - 1);
		quickSort(number, pi + 1, high);
	}
}


#endif

