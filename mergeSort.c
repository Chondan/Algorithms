#include <stdio.h>
#include <malloc.h>

void mergeSort(int *arr, int start, int end); // divide
void merge(int *arr, int start, int mid, int end); // conquere

int main(void) {
    int n;
    int *numbers = malloc(sizeof(int) * n);
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array seperated by space.\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    mergeSort(numbers, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void mergeSort(int *arr, int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    // divide to left array
    mergeSort(arr, start, mid);
    // divide to right array
    mergeSort(arr, mid + 1, end);
    // conquere
    merge(arr, start, mid, end);
}

void merge(int *arr, int start, int mid, int end) {
    int temp[end - start + 1], k = 0;
    int i = start, j = mid + 1;

    // compare element of 2 arrays to fill into temp array then shift the index 1 position until one of arrays is full 
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    // if one side of array is full then fill the remaining element of another side array
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }
    // copy from temp to arr
    for (i = start; i < end + 1; i++) {
        arr[i] = temp[i - start];
    }
}

