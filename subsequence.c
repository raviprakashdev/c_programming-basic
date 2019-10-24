#include <stdio.h>
#include <string.h>
typedef long long int lld;

//s1 and s2 are strings whose longest length of common subsequence is to be found out
char s1[1002], s2[1002];

int main()
{
    //input from user for the two strings
    scanf("%s %s", s1, s2);

    lld l1 = strlen(s1), l2 = strlen(s2), ans;

    int dd[1005][1005];
    int i, j;

    //putting all the values inside the 2d array as 0
    for (i = 0; i <= l1; i++)
    {
        for (j = 0; j <= l2; j++)
        {
            dd[i][j] = 0;
        }
    }
    
    for (i = l1 - 1; i >= 0; i--)
    {
        for (j = l2 - 1; j >= 0; j--)
        {
            if (i == l1 || j == l2)
            {
                dd[i][j] = 0;
            }
            else if (s1[i] == s2[j])
            {
                dd[i][j] = 1 + dd[i + 1][j + 1];
            }
            else
                dd[i][j] = dd[i + 1][j] > dd[i][j + 1] ? dd[i + 1][j] : dd[i][j + 1];
        }
    }
    printf("%d\n", dd[0][0]);

    return 0;
}