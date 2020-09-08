#include <stdio.h>
#include </home/chondan/Desktop/CHONDAN/CS50-Harvard/sorting/myLibrary.c>

void selectionSort(int *arr, int size);

int main(void) {
    int *x = get_IntegerArray(5);
    selectionSort(x, 5);
    printf("Sorted array: ");
    loopThrougArray(x, 5);
    
}
void selectionSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int min = arr[i], temp = arr[i], minPosition;
        for (int j = i; j < size; j++) {
            if (arr[j] <= min) {
                min = arr[j];
                minPosition = j;
            } 
        } 
        arr[i] = min;
        arr[minPosition] = temp;
    }
}