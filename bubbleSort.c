#include <stdio.h>
#include <malloc.h>

void bubbleSort(int *arr, int size);
void loopThroughArray(int *arr, int size);

int main(void) {
    printf("Enter size of array: ");
    int n, *array;
    scanf("%d", &n);
    array = malloc(sizeof(int) * n);
    printf("Enter elements of array separated by space\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, n);
    loopThroughArray(array, n);
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            int temp = arr[j];
            if (arr[j + 1] < arr[j]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void loopThroughArray(int *arr, int size) {
    for (int i = 0; i < size; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}