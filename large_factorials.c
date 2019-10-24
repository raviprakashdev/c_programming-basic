#include <stdio.h>

// This function multiplies x with the number represented by digit[]. 
// len is size of digit[] or number of digits in the number represented by digit[]
// simple elementary school multiplication  
long long int multiply(long long int x, long long int digit[], long long int len)
{

    long long int carry = 0, i, prod;

    for (i = 0; i < len; i++)
    {
        prod = digit[i] * x + carry;
        digit[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry){
        digit[len] = carry % 10;
        carry = carry / 10;
        len++;
    }
    return len;
}

int main()
{

    long long int t, i, n;

    // t= no. of test cases, n= no. whose factorial is to be found out 
    scanf("%lld", &t);

    while (t--)
    {
        scanf("%lld", &n);
        long long int j = 1, digit[20000] = {0}, len = 1;
        digit[0] = 1;

        for (j = 1; j <= n; j++)
        {
            len = multiply(j, digit, len);
        }

        for (i = len - 1; i >= 0; i--)
        printf("%lld", digit[i]);
        
        printf("\n");
    }

    return 0;
}