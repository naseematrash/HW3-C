#include <stdio.h>

#define SIZE 10

void shift_element(int* arr, int i) {
    for (int j = i; j > 0; --j)
        *(arr + j) = *(arr + j - 1);
}



void insertion_sort(int* arr, int len) {
    for (int i = 1; i < len; ++i)
    {
        int current = *(arr + i);
        int  j = (i - 1);

        while (j >= 0 && *(arr + j) > current)
            --j;

        shift_element((arr + j), (i - j));

        *(arr + j + 1) = current;
    }
}

int main() {
    int arr[SIZE] = { 0 };
    for (int i = 0; i < SIZE; ++i){
        scanf("%d", &(*(arr+i)));
        }

    insertion_sort(arr, SIZE);

    for (int i = 0; i < SIZE; ++i) {
        printf("%d%c", *(arr + i), ((i == (SIZE - 1)) ? '\n' : ','));
    }
    return 0;
}
