#include<stdio.h>
int partition(int arr[], int start, int end){
	int pivot = end;
	int pIndex = start, i = start;
	while(i < end){
		if(arr[i] < arr[pivot]){
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex++;
			i++;
		}else{
			i++;
		}
	}
	int temp = arr[pIndex];
	arr[pIndex] = arr[pivot];
	arr[pivot] = temp;
	return pIndex;
}

void quickSort(int arr[], int start, int end){
	if(start < end){
		int pIndex = partition(arr, start, end);
		quickSort(arr, start, pIndex - 1);
		quickSort(arr, pIndex + 1, end);
	}
}

void insertionSort(int arr[], int n){
	int i;
	for(i = 1; i < n; i++){
		int j = i;
		while(j > 0 && arr[j] < arr[j - 1]){
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

void selectionSort(int arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		int min = i, j;
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	
}

void bubbleSort(int arr[], int n){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i - 1; j++){
			if(arr[j + 1] < arr[j]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printArr(int arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[] = {10, 20, 40, 5, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("After quick sort, array elements are: \n");
	printArr(arr, n);
	
	int arr1[] = {10, 20, 40, 5, 15};
	insertionSort(arr1, n);
	printf("After insertion sort, array elements are: \n");
	printArr(arr1, n);
	
	int arr2[] = {10, 20, 40, 5, 15};
	selectionSort(arr2, n);
	printf("After selection sort, array elements are: \n");
	printArr(arr2, n);
	
	int arr3[] = {10, 20, 40, 5, 15};
	bubbleSort(arr3, n);
	printf("After bubble sort, array elements are: \n");
	printArr(arr3, n);
	return 0;
}
