#include <stdio.h>
#define ARRAY_LENGTH 7

int* insertion_sort(int array[], int size) {
    int i, key, j;  
    for (i = 1; i < size; i++)
    {  
        key = array[i];  
        j = i - 1;  
        while (j >= 0 && array[j] > key) 
        {  
            array[j + 1] = array[j];  
            j--;
        }

        array[j + 1] = key;  
    }  
}

void print_array(int array[], int size) {
    int i;

    for(i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void main() {
	int array[ARRAY_LENGTH] = { 2, 1, 6, 8, 9, 3, 2 };
	print_array(array, ARRAY_LENGTH);
    printf("sorting\n");
    insertion_sort(array, ARRAY_LENGTH);
    print_array(array, ARRAY_LENGTH);
}   
