#include <stdio.h>

unsigned int *freakybitsort(unsigned int *array, int size)
{
    unsigned int var = 1;
    unsigned int temp = 0;

    while (var < 0xffffffff && var > 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if ((var & array[j]) > (var & array[j + 1])) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        var = var << 1;
    }
    return array;
}

void print_array(unsigned int *array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    #define SIZE 10
    unsigned int array[SIZE] = {8, 4, 6, 1, 12, 0, 6500, 42, 77, 4};

    print_array(array, SIZE);
    freakybitsort(array, SIZE);
    print_array(array, SIZE);
    return 0;
}
