#include <stdio.h>
#include <malloc.h>

int* get_IntegerArray(int size) {
    int *numbers = malloc(sizeof(int) * size);
    printf("Enter elements of array seperated by space (%d elemets).\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    return numbers;
}

void loopThrougArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}