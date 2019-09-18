#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;  
  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[low];
    int i = low;
  
    for (int j = low+1; j <= high; j++)  
    {   
        if(arr[j]%2 !=0){
          arr[j]= arr[j]-1;
        }
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    
    swap(&arr[i], &arr[low]);
    return i;  
}  
  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  


int main()  
{  
    int arr[] = {6,1,8,5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    printArray(arr, n);  
    return 0;  
}  