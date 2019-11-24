
#include<iostream>
#include <time.h>

using namespace std;
void selectionSort(int arr[], int size)
{
	int j = 0;
	int tmp = 0;
	for (size_t i = 0; i < size; i++)
	{
		j = i;
		for (size_t k = i;  k < size;  k++)
		{
			if (arr[j] > arr[k])
				j = k;
		}
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

void bubbleSort(int arr[], int size)
{
	int tmp = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size-1; j >= i+1; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}
void insertionSort(int arr[], int size)
{
	int key = 0;
	int i = 0;
	for (size_t j = 1; j < size; j++)
	{
		key = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			--i;
			arr[i + 1] = key;
		}
	}
}
void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR) {
	int i = 0;
	int j = 0;
	while (i < lenL || j < lenR) {
		if (i < lenL && j < lenR) {
			if (L[i] <= R[j]) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i < lenL) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j < lenR) {
			merged[i + j] = R[j];
			j++;
		}
	}
}
void mergeSort(int arr[], int size)
{
	if (size > 1)
	{
		int middle = size / 2;
		int rem = size - middle;
		int*L = new int[middle];
		int*R = new int[rem];
		for (size_t i = 0; i < size; i++)
		{
			if (i < middle)
			{
				L[i] = arr[i];
			}
			else
			{
				R[i - middle] = arr[i];
			}
		}
		mergeSort(L, middle);
		mergeSort(R, rem);
		merge(arr, size, L, middle, R, rem);
	}
}



void fillArr(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}
void showArr(int arr[], int size)
{
	
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	
}




int main()
{
	
	 double start_time, end_time, search_time;

	int arr[100000];
	fillArr(arr, 100000);

	start_time = clock();
	selectionSort(arr, 100000);
	end_time = clock();
	search_time = (end_time - start_time)/ CLOCKS_PER_SEC;
	cout << "bubbleSort " << search_time << "ms" << endl;

	fillArr(arr, 100000);
	start_time = clock();
	insertionSort(arr, 100000);
	end_time = clock();
	search_time = (end_time - start_time) / CLOCKS_PER_SEC;
	cout << "insertionSort " << search_time << "ms" << endl;

	fillArr(arr, 100000);
	start_time = clock();
	selectionSort(arr, 100000);
	end_time = clock();
	search_time = (end_time - start_time) / CLOCKS_PER_SEC;
	cout << "selectionSort " << search_time << "ms" << endl;

	fillArr(arr, 100000);
	start_time = clock();
	mergeSort(arr, 100000);
	end_time = clock();
	search_time = (end_time - start_time) / CLOCKS_PER_SEC;
	cout << "mergeSort " << search_time << "ms" << endl;


	system("pause");
		

	return 0;
}
