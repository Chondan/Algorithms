#include <stdio.h>
#include <stdbool.h>
typedef char* string;

void sortArray(int array[], int size);
void loopThroughArray(int array[], int size);
bool binarySearch(int array[], int size, int findingNumber);
void searchingNumberInArray(int array[], int size);

int main(void) {
    int numbers[] = {9, 8, 7, 6, 5, 4, 12, 3, 4, 22, 25, 66, 7, 8, 99, 30, 100};
    int len = sizeof(numbers)/sizeof(int);
    searchingNumberInArray(numbers, len);
}

void sortArray(int array[], int size) {
    int* ptr;
    for (int x = 0; x < size; x++) {
        ptr = array;
        for (int i = 0; i < size; i++) {
            // sort numbers
            int temp = *ptr;
            if (*ptr > *(ptr + 1)) {
                *ptr = *(ptr + 1);
                *(ptr + 1) = temp;
            }
            ptr++;
        }
    }
}

void loopThroughArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

bool binarySearch(int array[], int size, int findingNumber) {
    sortArray(array, size);
    int start = 0, middle, end = size - 1, check = 1;
    bool isFound = false;
    while (!isFound) {
        // check wheter there are only two numbers left
        if (end - start == 1) {
            if (array[start] == findingNumber) {
                printf("Found at %d times of searching\n", check);
                isFound = true;
                break;
            } else if (array[end] == findingNumber) {
                printf("Found at %d times of searching\n", check);
                isFound = true;
                break;
            } else {
                break;
            }
        }
        middle = (start + end) / 2;
        if (array[middle] == findingNumber) {
            printf("Found at %d times of searching\n", check);
            isFound = true;
            break;
        } else {
            if (array[middle] > findingNumber) {
                end = middle;
            } else {
                start = middle;
            }
            middle = (start + end) / 2;
        }
        check++;
    }
    
    return isFound;
}

void searchingNumberInArray(int array[], int size) {
    int finding;
    printf("Enter the number that you want to find: ");
    scanf("%d", &finding);
    printf("%d\n", binarySearch(array, size, finding));
}