#include <stdio.h>
#include <stdlib.h>
static int count;
void TOH(int n, int x, int y, int z)
{
    if (n >= 1)
    {
        TOH(n - 1, x, z, y);
        printf("\nMove Top disk from Tower : %d , to top of tower : %d\n", x, y);
        count++;
        TOH(n - 1, z, y, x);
    }
}
int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    if (a == (int)NULL)
    {
        a = 3;
    }
    printf("\nNumber of Disks : %d",a);
    TOH(a, 1, 2, 3);
    printf("\nTotal Movement : %d", count);
    return 0;
}
