#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    
    int showermin = get_int();
    int bottles = showermin * 12;
    printf("Bottles: %d\n", bottles);
    return (0);
}