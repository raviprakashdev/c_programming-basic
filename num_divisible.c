#include <stdio.h>
main()
{
        int i;
        printf(" First 100 numbers which are divisible by 3 and 5 ");
 
        for (i=1; i<=100; i++)
        {
               if (i%3==0 && i%5==0)
                  printf(" %d", i);
        }
        getch();
} 