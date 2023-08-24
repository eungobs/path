#include <stdio.h>

void printIntArray(const int *array, size_t length);

int main() 
{
    int numbers[] = {3, 2, 1};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printIntArray(numbers, length);

    return (0);
}
void printIntArray(const int *array, size_t length) 
{
    for (size_t i = 0; i < length; i++) 
    {
        printf("%d\n", array[i]);
    }
}
