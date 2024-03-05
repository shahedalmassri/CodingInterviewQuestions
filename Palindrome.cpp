#include <math.h>
#include <cstdlib>
#include <stdio.h>

bool isPalindrome(int x) {
    // get the digits of the number
    if (x < 0)
    {
        return false;
    }
    int numDigits = (int)(log10(x) + 1);
    /*int* digits = (int*)malloc(numDigits * sizeof(int));
    if (digits == NULL) {
        exit(EXIT_FAILURE);
    }*/
    int* digits = new int[numDigits];
       
    for (int i = 0; i < numDigits; i++)
    {
        digits[i] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < (numDigits / 2); i++)
    {
        if (digits[i] != digits[numDigits - 1 - i])
        {
            delete[] digits;
            return false;
        }
    }
    delete[] digits;
    return true;
}

/*int main(void)
{
    if (isPalindrome(121)) {
        printf("true");
    }
    else {
        printf("False");
    }
}*/