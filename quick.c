#include <stdio.h>

// Swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition: places pivot at its correct position, returns that index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;                       // wall

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);         // pivot to its place
    return i;
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // pivot index

        quickSort(arr, low, p - 1);   // sort left part
        quickSort(arr, p + 1, high);  // sort right part
    }
}

// Print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("After sorting:  ");
    printArray(arr, n);

    return 0;
}
