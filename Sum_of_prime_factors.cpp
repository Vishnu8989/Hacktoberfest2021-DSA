#include <iostream>
#include <math.h>
using namespace std;
int num;
int d[100000] = {0};
void prime_generator(int num_o)
{
    int k = 2;
    int num = num_o;
    num = (int)sqrt(num_o);
    num = num + 1;
    while (k < num)
    {
        for (int i = 2 * k; i < num_o - k + 1; i = i + k)
        {
            d[i] = 1;
        }
        k++;
    }
}
int isPrime(int a)
{
    return !d[a];
}
int sumPrimeFactor(int a)
{
    int k = a;
    int sum = 0;
    for (int i = 2; i < k; i++)
    {
        if (a % i == 0 && isPrime(i))
        {
            printf("\nAdding %d",i);
            sum = sum + i;
        }
    }
    return sum;
}
int main()
{
    printf("\nEnter Number to get sum of prime factor (max 100000) : ");
    scanf("%d", &num);
    if(num > 100000){
        printf("Max limit Excedded");
        exit(99);
    }
    prime_generator(num);
    printf("\nSum of prime is : %d", sumPrimeFactor(num));
    return 0;
}
