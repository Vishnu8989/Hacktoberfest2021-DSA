#include <stdio.h>
#include <stdlib.h>
void i_sort(int *d, int a)
{
    int i, j, temp;                  //declare 2 variable for counting and one for storage
    for (int i = 1; i < a; i++)      //for loop for each element in array start from 1 as we compare atleast two elements
    {
        temp = d[i];       // store the last element of current array
        j = i - 1;         //assign var to second last element
        while (d[j] > temp && j >=0)   // loop till last element in array or till find the number is fit
        {
            d[j + 1] = d[j];     //keep traversing while moving element forward
            j--;                 //loop ender
        }
        // printf("J : %d\n", j);
        d[j+1] = temp;      //after finding j put value of element to j;
    }
}
int main()
{
    int a = 7;
    printf("a = %d\n", a);
    int *d = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        d[i] = rand() % 100;
        printf("\t%d", d[i]);
    }
    printf("\n");
    i_sort(d, a);
    for (int i = 0; i < a; i++)
    {
        printf("\t%d", d[i]);
    }
    return 0;
}
