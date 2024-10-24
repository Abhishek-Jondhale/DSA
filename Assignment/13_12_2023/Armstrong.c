#include <stdio.h>
#include <math.h>

int countDigits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

int isArmstrong(int num)
{
    int originalNum = num;
    int numDigits = countDigits(num);
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }

    return (originalNum == sum);
}

int main()
{
    int count = 0;
    int num = 0;

    while (count < 10)
    {
        if (isArmstrong(num))
        {
            printf("%d\n", num);
            count++;
        }
        num++;
    }

    return 0;
}
