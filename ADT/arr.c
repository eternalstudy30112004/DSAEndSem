#include <stdlib.h>
#include <limits.h>
typedef struct array
{
    int *data;
    int size;
    int length;
} array;

void init(array *arr, int size)
{
    arr->data = (int *)malloc(sizeof(int) * size);
    if (!arr->data)
        return;
    arr->length = 0;
    arr->size = size;
    return;
}

void append(array *arr, int val)
{
    if (arr->length >= arr->size)
        return;
    arr->data[arr->length++] = val;
    return;
}

void insertAtIndex(array *arr, int pos, int val)
{
    if (arr->length >= arr->size || (pos < 0 || pos > arr->length))
        return;
    if (pos == arr->length)
    {
        append(arr, val);
        return;
    }
    for (int i = arr->length; i > pos; i--)
    {
        arr->data[i] = arr->data[i-1];
    }
    arr->data[pos] = val;
    arr->length++;
    return;
}

void removeAtIndex(array *arr, int pos)
{
    if (!arr->length)
        return;
    for (int i = pos; i < arr->length; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
    return;
}

void display(array arr)
{
    printf("\n[ ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.data[i]);
    }
    printf(" ]\n");
}
int max(array arr)
{
    int m = INT_MIN;
    for (int i = 0; i < arr.length; i++)
    {
        if (m < arr.data[i])
            m = arr.data[i];
    }
    return m;
}
int min(array arr)
{
    int m = INT_MAX;
    for (int i = 0; i < arr.length; i++)
    {
        if (m > arr.data[i])
            m = arr.data[i];
    }
    return m;
}
void swap(array *arr, int i, int j)
{
    int temp = arr->data[i];
    arr->data[i] = arr->data[j];
    arr->data[j] = temp;
    return;
}
void reverse(array *arr)
{
    int start = 0;
    int end = arr->length - 1;
    while (start < end)
    {
        swap(arr, start++, end--);
    }
    return;
}

void merge(array *arr1, array arr2)
{
    int i = 0;
    while ((arr1->length + arr2.length) < arr1->size && i < arr2.length)
    {
        append(arr1, arr2.data[i++]);       
    }
    return;
}
