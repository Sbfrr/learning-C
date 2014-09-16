#include <stdio.h>
/* Implement a basic quick sort in C*/

void exchange(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void quickSort(int array[], int start, int end)
{
    int left = start-1;
    int right = end+1;
    const int pivot = array[start];

    if(start >= end)
        return;

    while(1)
    {
        do right--; while(array[right] > pivot);
        do left++; while(array[left] < pivot);

        if(left < right)
            exchange(array, left, right);
        else break;
    }

    quickSort(array, start, right);
    quickSort(array, right+1, end);
}

int main(void)
{
    int tab[6] = {8, 11, 3, 6, 9, 10};
    int i;

    quickSort(tab, 0, 5);

    for(i = 0; i < 5; i++)
    {
      printf("%d ", tab[i]);
    }
    putchar('\n');

    return 0;
}
