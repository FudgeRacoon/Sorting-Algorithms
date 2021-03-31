#include<iostream>		
using namespace std;

class HeapSort
{
public:
	static int* GetParent(int* array, int index)
	{
		return &array[(index - 1) / 2];
	}
	static int* GetLeftChild(int* array, int index)
	{
		return &array[(index * 2) + 1];
	}
	static int* GetRightChild(int* array, int index)
	{
		return &array[(index * 2) + 2];
	}

	static void Swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	static void Heapify(int* array, int size)
	{
		for(int index = 1; index < size; index++)
		{
			while(index > 0 && array[index] > *GetParent(array, index))
			{
				Swap(&array[index], GetParent(array, index));
				index = (index - 1) / 2;
			}
		}	
	}

	static void Sort(int* array, int size)
	{
		for(int j = 1; j < size; j++)
		{
			int index = 0;
			int child = (index * 2) + 1;
			int temp = array[index];

			array[index] = array[size - j];

			while(child < size - j)
			{
				if(array[child] < array[child + 1])
					child += 1;
				if(array[child] > array[index])
				{
					Swap(&array[child], &array[index]);
					index = child;
					child = (index * 2) + 1;
				}
				else
					break;
			}

			array[size - j] = temp;
		}
	}	
};

int main()
{
	int size = 10;

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

	HeapSort::Heapify(array,size);
	HeapSort::Sort(array, size);

	cout << "Array after sorting:" << endl;
	for(int i = 0; i < size; i++)
		cout << "\telement " << i << " >> " << array[i] << endl;

	getchar();
}

