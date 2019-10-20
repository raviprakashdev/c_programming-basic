#include <stdio.h>

int main()
{

    reverse_it("hacktoberfest");
}

int reverse_it(char *string)
{
    char *duplicated = strdup(string);
    int counter = strlen(string);
    for (int i = counter - 1; i > -1; i--)
    {
        printf("Word is:%c\n", duplicated[i]);
    }
}