#include<iostream>
using namespace std;

class InsertionSort
{
	public:
		static void Sort(int* array, int size)
		{
			for(int index = 1; index < size; index++)
			{
				int marker = array[index];
				int pointer = index - 1;

				while(pointer >= 0 && marker < array[pointer])
				{
					array[pointer + 1] = array[pointer];
					pointer--;
				}
				array[++pointer] = marker;
			}
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

	InsertionSort::Sort(array, size);

	cout << "Array after sorting:" << endl;
	for(int i = 0; i < size; i++)
		cout << "\telement " << i << " >> " << array[i] << endl;
}
