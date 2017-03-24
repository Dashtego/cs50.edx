#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int values[], int n)
{
    int temp = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        if (values[i] >values[i + 1]) //bubble sort method
        {
            temp = values[i];
			values[i] = values[i + 1];
			values[i + 1] = temp;
			i = 0; //reset and start at begining of list after a swap is made
        }
    }
    /*int i = 0;
    printf("[");
    while (i < n)
    {
        
        printf("%i, ", values[i]);
        i++;
    }
    printf("]");*/ //uncomment this to print the list after the sort function, for debugging
}

int     bisearch(int needle, int hay[], int left, int right)
{
    int mid;
    if (left > right)
    {
        return (0);
    }
    mid = ((left + right) / 2); //set the middle of the list 
    if (hay[mid] == needle)
    {
        return (1);
    }
    if (hay[mid] < needle) 
    {
        return (bisearch(needle, hay, mid + 1, right)); //search right half of values
    }
    if (hay[mid] > needle) 
    {
        return (bisearch(needle, hay, left, mid - 1));  //search left half of values
    }
    return (0);
}

bool search(int value, int values[], int n)
{
    int     res = 0;
    if (n < 0)
    {
        return (false);

    }
    res = bisearch(value, values, 0, n - 1);
    if (res == 1)
    {
        return (true);
    }
    return (false);
}