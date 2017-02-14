#include <stdio.h>
#include <cs50.h>
#include <unistd.h>


void    printpy(int ht, int max)
{
    int     i = 0;
    while (i < max - 1)
    {
        printf(" ");
        i++;
    }
    i = 0;
    while (i <= (ht))
    {
        printf("#");
        i++;
    }
    printf("  ");
    i = 0;
    while (i <= (ht))
    {
        printf("#");
        i++;
    }
}



int main(void)
{
    int     j = 0;
    printf("Height: ");
    int ht = get_int();
    while (ht > 23 || ht < 0){
        printf("Height: ");
        ht = get_int();
    }
    if (ht == 0)
    {
        return (0);
    }
    int max = ht;
    while (j < ht)
    {
        printpy(j, max);
        printf("\n");
        j++;
        max--;
    }
    return (0);
}