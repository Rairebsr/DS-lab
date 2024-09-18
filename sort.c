#include <stdio.h>
#include <stdlib.h>

// Bubble Sort
void bubble(int *arr, int n) {
    int i, j, swap, temp;

    for (i = 0; i < n - 1; i++) {
        swap = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0) {
            break;
        }
    }
}

// Selection Sort
void selection(int *arr, int n) {
    int i, j, temp, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;  // Correctly find the minimum element
            }
        }
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// Insertion Sort
void insertion(int *arr, int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {  // Start from the second element
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot to the correct position
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

// Quick Sort
void quick(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}
void display(int *arr,int n)
{
    int i;
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }    
}
int main() {
    int i, n;
    int arr[30];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
int num,c;
    do{
        printf("\nenter choice\n 1.selection\n 2.bubble\n 3.insertion\n 4.quick\n");
        scanf("%d",&c);
        
        switch(c){
            case 1:
                selection(arr,n);
                display(arr,n);
                break;
            case 2:
                bubble(arr,n);
                display(arr,n);
                break;
            case 3: 
                insertion(arr,n);
                display(arr,n);
                break;
            case 4:
                quick(arr,0,n-1);
                display(arr,n);
                break;

            default: printf("invalid option");
        }
    }while(c!=5);
    
    
    printf("\n");

    return 0;
}
