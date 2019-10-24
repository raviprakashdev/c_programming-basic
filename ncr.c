//This program finds combination of n objects taken r at a time (ncr)
//For very big values we take %m.

#include <stdio.h>

typedef long long int lld;

int main()
{

    lld n, r, i, j, dp[1002][1002];
    lld m = 1000000007;

    scanf("%lld %lld", &n, &r);

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (i == 0 || i == 1)
                dp[i][j] = 1;

            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % m;
        }
    }

    printf("%lld\n", dp[n][r] % m);

    return 0;
}