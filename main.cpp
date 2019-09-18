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
    int pivot = arr[high];
    int i = low-1;

    for (int j = low; j <= high-1; j++)  
    {   
        if(arr[j]%2 !=0) {
          arr[j]=arr[j]-1;
        }
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    
    swap(&arr[i+1], &arr[high]);
    
    return i+1;  
}  
  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }
    if(arr[high]%2!=0) arr[high]-=1;
}  


int main()  
{  
    int arr[] = {1,3,6,7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    printArray(arr, n);  
    int ant=0;
    for(int i=0; i<n;i++){
      if(arr[i]-ant>2){
        arr[i]=arr[i]-2;
      }
      ant=arr[i];
    }
    printArray(arr, n);
    return 0;  
}  