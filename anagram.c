#include <stdio.h>
#include <string.h>
int main()
{
    char p[100003], q[100003];
    long long int len1, len2, i, j;

    int a[257] = {0}, b[257] = {0};
    j = 0;

    //strings which are to be checked if anagram or not
    scanf("%s %s", p, q);

    //len1=length of p, len2= length of q
    len1 = strlen(p);
    len2 = strlen(q);

    if (len1 != len2)
        printf("No\n");

    else
    {
        for (i = 0; i < len1; i++)
            a[p[i]]++;

        for (i = 0; i < len2; i++)
            b[q[i]]++;

        for (i = 0; i < 257; i++)
        {

            if (a[i] != b[i])
            {
                printf("No\n");
                break;
            }
        }

        if (i == 257)
            printf("Yes\n");
    }

    return 0;
}