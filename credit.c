#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int     crdlen(unsigned long long c)
{
    int     i = 0;
    
    while (c > 10)
    {
        c /= 10;
        i++;
    }
    i++;
    return (i);
}

int     crdchk(int len, unsigned long long c)
{
    int     chksum = 0;
    while (c > 9)
    {
        chksum += (c % 10);
        c /= 10;

        if (c < 9)
        {
            break;
        }
        if (((c % 10) * 2) > 9)
        {
            chksum += (((c % 10) * 2) % 10);
            chksum += (((c % 10) * 2) / 10);
        }
        else
        {
            chksum += ((c % 10) * 2);
        }
        c /= 10;
    }
    if (len % 2 == 0)
    {
        if (((c % 10) * 2) > 9)
        {
            chksum += (((c % 10) * 2) % 10);
            chksum += (((c % 10) * 2) / 10);
        }
        else
        {
            chksum += ((c % 10) * 2);
        }
    }
    else
    {
        chksum += (c);
    }
    if (chksum % 10 == 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int    company(int len, unsigned long long cardnum)
{
    if (len == 15 && ((cardnum / 10000000000000) == 34 || (cardnum / 10000000000000) == 37))
    {
        return (1);
    }
    else if (len == 16 && ((cardnum / 100000000000000) >= 51 && (cardnum / 100000000000000) <= 55))
    {
        return (2);
    }
        else if (len == 16 && ((cardnum / 1000000000000000) == 4))
    {
        return (3);
    }
    else if (len == 13 && ((cardnum / 1000000000000) == 4))
    {
        return (3);
    }
    return (0);
}

int     main(void)
{
    int valid = 0;
    int len = 0;
    int comp = 0;
    printf("Number: ");
    unsigned long long cardnum = get_long_long();
    len = crdlen(cardnum);
    valid = crdchk(len, cardnum);
    comp = company(len, cardnum);
    if (valid == 0)
    {
        printf("INVALID\n");
        return (0);
    }
    else if (comp == 1)
    {
        printf("AMEX\n");
    }
    else if (comp == 2)
    {
        printf("MASTERCARD\n");
    }
    else if (comp == 3)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return (0);
}