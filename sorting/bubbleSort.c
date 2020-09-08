#include <stdio.h>
#include <malloc.h>
#include </home/chondan/Desktop/CHONDAN/CS50-Harvard/sorting/myLibrary.c>

void bubbleSort(int *arr, int size);
void loopThroughArray(int *arr, int size);

int main(void) {
    int *array = get_IntegerArray(5);
    bubbleSort(array, 5);
    loopThroughArray(array, 5);
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
