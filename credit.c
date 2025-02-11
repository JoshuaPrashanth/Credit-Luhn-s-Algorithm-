#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main()
{

    long num, num2, lennum, starnum;
    float rem, n, temp;
    int start1, start2, last, digit, add = 0, count = 1, count2 = 0, lencount = 0, flag = 0;

    num = get_long("\nEnter Credit card number: ");
    starnum = lennum = num2 = num; // To calculate Cecksum future use

    // CHECKSUM LOGIC
    //   -------------------------------------------------------------------------------------------------------------------------
    // From last second numbers:
    while (num > 0)
    {
        last = num % 10;    // To get last digit of credit card number
        if (count % 2 == 0) // To get digit one after the other from last second digit
        {
            digit = last * 2;
            if (digit > 9)
            {
                digit =
                    (digit - 9); // To split the numbers into to and add them both ex 14 = 1+4 = 5
            }
            add += digit;
        }
        num = num / 10; // To remove last digit from credit card number
        count++;
    }
    // printf("Total: %d\n",add);

    // From last numbers:
    while (num2 > 0)
    {
        last = num2 % 10;
        if (count2 % 2 == 0)
        {
            add += last;
        }
        num2 = num2 / 10;
        count2++;
    }
    if (add % 10 == 0)
    {
        // printf("Checksum: Passed\n");
        flag++;
    }
    else
    {
        // printf("Checksum: Failed\n");
    }

    // Length and Starting two digits
    // -------------------------------------------------------------------------------------------------------------------------
    while (lennum > 0)
    {
        lennum = lennum / 10;
        lencount++;
    }
    // printf("Length of credit card number is: %d\n", lencount);

    // Starting two digits
    // -------------------------------------------------------------------------------------------------------------------------
    temp = (float) starnum / pow(10, lencount - 1);
    start1 = (int) temp;
    temp = (float) starnum / pow(10, lencount - 2);
    start2 = (int) temp;
    // printf("Initial Digit: %d\n", start);

    // Check Credit Brand
    // -------------------------------------------------------------------------------------------------------------------------
    if (flag == 1)
    {
        if (lencount == 15 && (start2 == 34 || start2 == 37))
        {
            printf("AMEX\n");
        }
        else if (lencount == 16 && (start2 == 22 || start2 == 51 || start2 == 52 || start2 == 53 ||
                                    start2 == 54 || start2 == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((lencount == 13 || lencount == 16) && start1 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
