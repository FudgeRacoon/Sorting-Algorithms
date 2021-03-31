#include<iostream>
using namespace std;

class BubbleSort
{
public:
	static void Swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	static void Sort(int* array, int size)
	{
		for(int pass = 0; pass < size - 1; pass++)
			for(int index = 0; index < size - pass - 1; index++)
				if(array[index] > array[index + 1])
					Swap(&array[index], &array[index + 1]);
		
	}
};

int main()
{
	int size;

	cout << "Enter size of array: ";
	cin >> size;
	
	int array[size];

	cout << endl << "Enter the elements:" << endl;
	for(int i = 0; i < size; i++)
	{
		cout << "\telement " << i << " >> ";
		cin >> array[i];
	}

	cout << "Array before sorting:" << endl;
	for(int i = 0; i < size; i++)
		cout << "\telement " << i << " >> " << array[i] << endl;

	BubbleSort::Sort(array, size);

	cout << "Array after sorting:" << endl;
	for(int i = 0; i < size; i++)
		cout << "\telement " << i << " >> " << array[i] << endl;
}
