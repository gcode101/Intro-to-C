#include <stdio.h>
#include <stdlib.h>
#include <callbacks.h>
#include "lib.h"

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in ascending numerical order.
*/
int sorted_order(int a, int b)
{
    return b - a;
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
    return a - b;
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the
    sorted data. Call the callback as you would any other function.
*/
int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    int *sorted = malloc(n * sizeof(int));
    sorted = mem_copy(sorted, numbers, n);
    printf("%s", "sorted: ");
    for (int i = 0 ; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (cmp(sorted[i], sorted[i + 1]) > 0)
            {
                swap(&sorted[i], &sorted[i + 1]);
                swapped = 1;
            }
        }
    } while (swapped);
    return sorted;
}

#ifndef TESTING
int main(void)
{
    int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int count = sizeof(arr) / sizeof(arr[0]);
    int *sorted_arr;

    //sorted_arr = bubble_sort(arr, count, sorted_order);
    sorted_arr = bubble_sort(arr, count, reverse_order);

    for (int i = 0 ; i < count ; i++) {
        printf("%d ", sorted_arr[i]);
    }

    printf("\n");

    return 0;
}
#endif
