// Lab7.cpp
// Ryan Durnan
// COSC 2030
// Lab7
// 12 Nov 2018

#include "stdafx.h"
#include "RandomUtilities.h"
#include "winTimer.h"
#include "Lab7-rdurnan.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

// Build a vector full of random numbers.
vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}
	return theList;
}

int main()
{
	// Get information needed for creating random vector
	int size;
	unsigned int seed;
	cout << "Enter size for numbers:  ";
	cin >> size;
	cout << "Enter a seed for rand:  ";
	cin >> seed;

	// Set up timers for each sorting function
	Timer getSort;
	Timer getBub;
	Timer getIsrt;
	Timer getSlct;
	Timer getMerge;
	Timer getQuick;

	cout << "\nSort a vector of random numbers using sort() function from STL" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	// Create random vector for sort()
	cout << "Creating random vector..." << endl;
	vector<double> numbers = getNums(size, -size, size);
	cout << "Vector created. ";
	// Display information
	if (size < 10)
	{
		cout << "Here is your unsorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
		cout << "Sorting vector..." << endl;
		getSort.start();
		sort(begin(numbers), end(numbers));
		getSort.stop();
		cout << "Vector sorted in " << getSort() << " seconds. Here is your sorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "Sorting vector..." << endl;
		getSort.start();
		sort(begin(numbers), end(numbers));
		getSort.stop();
		cout << "Vector sorted in " << getSort() << " seconds." << endl << endl;
	}
	
	// Get information needed for creating random vector
	cout << "Enter size for numbers:  ";
	cin >> size;
	cout << "Enter a seed for rand:  ";
	cin >> seed;

	cout << "\nSort a vector of random numbers using bubble algorithm" << endl;
	cout << "------------------------------------------------------" << endl << endl;
	// Create random vector for bubble algorithm
	cout << "Creating random vector..." << endl;
	numbers = getNums(size, -size, size);
	cout << "Vector created. ";
	// Display information
	if (size < 10)
	{
		cout << "Here is your unsorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{ 
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			} 
		}
		cout << " )" << endl << endl;
		cout << "Sorting vector..." << endl;
		getBub.start();
		bubble(numbers);
		getBub.stop();
		cout << "Vector sorted in " << getBub() << " seconds. Here is your sorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "Sorting vector..." << endl;
		getBub.start();
		bubble(numbers);
		getBub.stop();
		cout << "Vector sorted in " << getBub() << " seconds." << endl << endl;
	}

	// Get information needed for creating random vector
	cout << "Enter size for numbers:  ";
	cin >> size;
	cout << "Enter a seed for rand:  ";
	cin >> seed;

	cout << "\nSort a vector of random numbers using insertion algorithm" << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	// Create random vector for insertion algorithm
	cout << "Creating random vector..." << endl;
	numbers = getNums(size, -size, size);
	cout << "Vector created. ";
	// Display information
	if (size < 10)
	{
		cout << "Here is your unsorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
		cout << "Sorting vector..." << endl;
		getIsrt.start();
		insertion(numbers);
		getIsrt.stop();
		cout << "Vector sorted in " << getIsrt() << " seconds. Here is your sorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "Sorting vector..." << endl;
		getIsrt.start();
		insertion(numbers);
		getIsrt.stop();
		cout << "Vector sorted in " << getIsrt() << " seconds." << endl << endl;
	}

	// Get information needed for creating random vector
	cout << "Enter size for numbers:  ";
	cin >> size;
	cout << "Enter a seed for rand:  ";
	cin >> seed;

	cout << "\nSort a vector of random numbers using selection algorithm" << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	// Create random vector for selection algorithm
	cout << "Creating random vector..." << endl;
	numbers = getNums(size, -size, size);
	cout << "Vector created. ";
	// Display information
	if (size < 10)
	{
		cout << "Here is your unsorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
		cout << "Sorting vector..." << endl;
		getSlct.start();
		selection(numbers);
		getSlct.stop();
		cout << "Vector sorted in " << getSlct() << " seconds. Here is your sorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "Sorting vector..." << endl;
		getSlct.start();
		selection(numbers);
		getSlct.stop();
		cout << "Vector sorted in " << getSlct() << " seconds." << endl << endl;
	}
	
	// Get information needed for creating random vector
	cout << "Enter size for numbers:  ";
	cin >> size;
	cout << "Enter a seed for rand:  ";
	cin >> seed;

	cout << "\nSort a vector of random numbers using merge algorithm" << endl;
	cout << "-----------------------------------------------------" << endl << endl;
	// Create random vector for merge algorithm
	cout << "Creating random vector..." << endl;
	numbers = getNums(size, -size, size);
	cout << "Vector created. ";
	// Display information
	if (size < 10)
	{
		cout << "Here is your unsorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
		cout << "Sorting vector..." << endl;
		getMerge.start();
		mergeSort(numbers, 0, numbers.size()-1);
		getMerge.stop();
		cout << "Vector sorted in " << getMerge() << " seconds. Here is your sorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "Sorting vector..." << endl;
		getMerge.start();
		mergeSort(numbers, 0, numbers.size()-1);
		getMerge.stop();
		cout << "Vector sorted in " << getMerge() << " seconds." << endl << endl;
	}
	
	// Get information needed for creating random vector
	cout << "Enter size for numbers:  ";
	cin >> size;
	cout << "Enter a seed for rand:  ";
	cin >> seed;

	cout << "\nSort a vector of random numbers using quick sort algorithm" << endl;
	cout << "----------------------------------------------------------" << endl;
	// Create random vector for quick sort algorithm
	cout << "Creating random vector..." << endl;
	numbers = getNums(size, -size, size);
	cout << "Vector created. ";
	// Display information
	if (size < 10)
	{
		cout << "Here is your unsorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
		cout << "Sorting vector..." << endl;
		getQuick.start();
		quickSort(numbers, 0, numbers.size()-1);
		getQuick.stop();
		cout << "Vector sorted in " << getQuick() << " seconds. Here is your sorted vector." << endl;
		cout << "( ";
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == (numbers.size() - 1))
			{
				cout << numbers[i];
			}
			else
			{
				cout << numbers[i] << ", ";
			}
		}
		cout << " )" << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "Sorting vector..." << endl;
		getQuick.start();
		quickSort(numbers, 0, numbers.size()-1);
		getQuick.stop();
		cout << "Vector sorted in " << getQuick() << " seconds." << endl << endl;
	}

    return 0;
}

