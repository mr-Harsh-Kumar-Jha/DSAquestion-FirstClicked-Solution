#include <stdio.h>
#define COINS 9
#define MAX 100000

void findMin(int cost,int coins[])
{
    int coinList[MAX] = { 0 };
    int i, k = 0;

    for (i = COINS - 1; i >= 0; i--)
    {
        while (cost >= coins[i])
        {
            cost -= coins[i];
            // Add coin in the list
            coinList[k++] = coins[i];
        }
    }

    for (i = 0; i < k; i++)
    {
        // Print
        printf("%d.]your required notes are: %d\n",i+1,coinList[i]);
    }
    return;
}

int main(void)
{
    // input value
    int n ;
// All denominations of Indian Currency
    int coins[] = { 1, 2, 5, 10, 20,50, 100, 200, 2000};

    printf("Enter the money to know which notes /& coins u will be provided: ");
    scanf("%d",&n);
    findMin(n,coins);
    return 0;
}
