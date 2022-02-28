#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdio.h> 

void swap (int *p , int * q )
{
    int tmp = *p;
    *p = *q;
    *q=tmp;
   
}

int partition_function(int arr[], int l, int h) 
{ 
	int p = arr[h]; 
	int i = (l - 1);  

	for (int j = l; j <= h- 1; j++) 
	{  
		if (arr[j] < p) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]);
		} 
	} 
	swap(&arr[i + 1], &arr[h]); 
	return (i + 1);   
} 

void sort(int arr[], int l, int h) 
{ 
	if (l < h) 
	{ 
		int p_index = partition_function(arr, l, h); 
		sort(arr, l, p_index - 1); 
		sort(arr, p_index + 1, h); 
	} 
} 
 
void print_Array(int arr[], int len) 
{ 
	int i; 
	for (i=0; i < len; i++) 
		printf("%d ", arr[i]);  
} 


int main() 
{ 
	int array[] = {14, 17, 8, 90, 11, 2};
	print_Array(array, 6);
	printf("\n");
        sort(array, 0, 5); 
	print_Array(array, 6); 
	return 0; 
} 