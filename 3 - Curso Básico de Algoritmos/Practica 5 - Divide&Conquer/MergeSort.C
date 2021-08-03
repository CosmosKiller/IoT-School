#include "stdio.h"
#include "stdlib.h"

void merge(int arr[],int l, int m, int h)
{
    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=h-m;

    int arr1[n1];
    int arr2[n2];


    for (i=0;i<n1;i++)
        arr1[i]=arr[l+i];
    for (j=0;j<n2;j++)
        arr2[j]=arr[m+j+1];
    

    i=0;
    j=0;
    k=l;

    while (i < n1 && j < n2)
    { 
        if (arr1[i] <= arr2[j])
        { 
            arr[k] = arr1[i]; 
            i++; 
        } 
        else { 
            arr[k] = arr2[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1)
    { 
        arr[k] = arr1[i]; 
        i++; 
        k++; 
    } 

    while (j < n2)
    { 
        arr[k] = arr2[j]; 
        j++; 
        k++; 
    }
}

void mergeSort(int arr[], int low, int high)
{
    
    if (low<high)
    {
        int mid = low + (high-low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr, mid+1, high);

        merge(arr,low,mid,high);
    }
}

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("]\n"); 
} 

int main()
{
int arr[] = { 12, 11, 13, 5, 6, 7 };
	
int n = sizeof(arr)/sizeof(arr[0]); 
mergeSort(arr, 0, n-1); 
printf("Arreglo ordenado: ["); 
printArray(arr, n); 
return 0; 

}