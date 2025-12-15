#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr = (int *)malloc(5 * sizeof(int));

    ptr[0] = 0;
    ptr[1] = 1;
    ptr[2] = 2;
    ptr[3] = 3;
    ptr[4] = 4;

    // Resize the array to hold 10 integers
    ptr = (int *)realloc(ptr, 10 * sizeof(int));
    for (int i = 5; i < 10; i++)
    {
        ptr[i] = i;
    }

    // free
    free(ptr);
    
    return 0;
}